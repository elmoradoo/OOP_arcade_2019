/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core
*/

#include <dlfcn.h>
#include "../../lib/ILib.hpp"
#include <iostream>

typedef ILib *(*entry_point)();

int getLib(char *lib)
{
    std::string filename(lib);
    std::string s = "./" + filename;
    void *handle = dlopen(s.c_str(), RTLD_LAZY);
    entry_point entry;

    std::cout << "salut [" << s << "]" << std::endl;
    if (handle == nullptr)
        return (-1);
    void *tmp = dlsym(handle, "entry_point");
    entry = (entry_point)tmp;
    ILib *Mourad = entry();
    std::cout << "salut" << std::endl;
    Mourad->print();
    return (0);
}



//  void *handle;
//     void (*func_print_name)(void);

//     handle = dlopen("./foo.so", RTLD_LAZY);
//     if (!handle) {
//         /* fail to load the library */
//         std::cout << "Library loading failed abort abort ffs" << std::endl;
//         return -1;
//     }
//     *(void**)(&func_print_name) = dlsym(handle, "entry_point");
//     func_print_name();
//     dlclose(handle);

