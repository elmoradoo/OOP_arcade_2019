/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "circle.hpp"
#include <iostream>
#include <dlfcn.h>
 
using namespace std;
 
int main(int argc, char **argv)
{
    void *hndl;
    maker_circle pMaker;
    delete_circle pDelete;
 
    hndl = dlopen("./libcircle.so", RTLD_LAZY);
    if(hndl == NULL) {
		cerr << "dlopen : "<< dlerror() << endl; 
		exit(EXIT_FAILURE);
    }
    void *mkr = dlsym(hndl, "make_circle");
    if (mkr == NULL) {
		cerr << "dlsym : " << dlerror() << endl;
		exit(EXIT_FAILURE);
    }
    pMaker = (maker_circle)mkr;
    circle *my_circle = pMaker();
    my_circle->draw();
    // mkr = dlsym(hndl, "delete_circle");
    // pDelete = (delete_circle)mkr;
    // pDelete();
    dlclose(hndl);
    return EXIT_SUCCESS;
}