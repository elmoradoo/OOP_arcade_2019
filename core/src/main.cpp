/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

//
// dlopen 
// dlsym
// dlclose
// dlerror
//

#include "dlHandler.hpp"

int main(int ac, char **av)
{
    std::string libPath = ac == 2 ? av[1] : "nullptr";
    if (libPath == "nullptr")
        return (84);
    dlHandler hdl;
    hdl.loadLib(libPath);
    return (0);
}