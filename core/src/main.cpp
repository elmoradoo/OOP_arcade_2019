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
#include "../../lib/ILib.hpp"


int main(int ac, char **av)
{
    std::string libPath = ac == 2 ? av[1] : "nullptr";
    if (libPath == "nullptr")
        return (84);
    dlHandler hdl;
    std::cout << "ok" << std::endl;
    hdl.loadLib(libPath);
    ILib *lib = hdl.getLib();
    lib->print();
    hdl.unLoadLib();
    return (0);
}