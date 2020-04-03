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
#include "menu.hpp"
#include "ILib.hpp"


int main(int ac, char **av)
{
    std::string libPath = ac == 2 ? av[1] : "nullptr";
    if (libPath == "nullptr")
        return (84);
    dlHandler hdl;
    std::cout << "ok" << std::endl;
    hdl.loadLib(libPath);
    ILib *lib = hdl.getLib();
    menu ste;
    ste.loop(lib);
    hdl.unLoadLib();
    return (0);
}