/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_ncurses
*/

#include <iostream>
#include "include/my_ncurses.hpp"

ILib *lib = nullptr;

myNcurses::myNcurses()
{

}
void myNcurses::print()
{
    std::cout << "ncusrses" << std::endl;
}

__attribute__((constructor)) void load_lib()
{
    lib = new myNcurses();
}

__attribute__((destructor)) void unload_lib()
{
    delete lib;
}

extern "C" ILib *entry_point()
{
    return (lib);
}