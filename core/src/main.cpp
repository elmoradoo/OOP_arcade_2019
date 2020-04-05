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
    setlocale(LC_ALL, "");
    std::string libPath = ac == 2 ? av[1] : "nullptr";
    std::string game;
    if (libPath == "nullptr")
        return (84);
    dlHandler hdl;
    hdl.loadLib(libPath);
    menu ste;
    hdl.getLib();
    game = ste.loop(hdl);
    game = "./games/" + game;
    if (game.find("nothing") != static_cast<long unsigned int> (-1))
        return (0);
    // hdl.unLoadLib();
    gameHandler gHandl;
    gHandl.loadLib(game);
    IGame *gm;
    gm = gHandl.getLib();
    gm->loop(hdl);
    return (0);
}