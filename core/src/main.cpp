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
#include "dlHandlerGame.hpp"

int main(int ac, char **av)
{
    std::string libPath = ac == 2 ? av[1] : "nullptr";
    std::string game;
    if (libPath == "nullptr")
        return (84);
    dlHandler hdl;
    std::cout << "ok" << std::endl;
    hdl.loadLib(libPath);
    menu ste;
    hdl.getLib();
    game = ste.loop(hdl);
    game = "./games/" + game;
    // hdl.unLoadLib();
    gameHandler gHandl;
    gHandl.loadLib(game);
    IGame *gm;
    gm = gHandl.getLib();
    gm->loop(hdl);
    return (0);
}