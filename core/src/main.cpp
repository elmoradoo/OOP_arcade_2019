/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "dlHandler.hpp"
#include "menu.hpp"
#include "ILib.hpp"
#include "dlHandlerGame.hpp"

void printName()
{
    std::string name;

    std::cout << "Enter your name:" << std::endl;
    std::cin >> name;
    std::cout << "Hello " << name << " !" << std::endl;
}

void progloop(menu &ste, dlHandler hdl, gameHandler &gHandl)
{
    std::string game;
    IGame *gm = gHandl.getLib();
    int input = gm->loop(hdl);

    if (input == 1)
        game = "./games/" + ste.loop(hdl);
    else if (input == 2)
        game = "./games/lib_arcade_nibbler.so";
    else if (input == 3)
        game = "./games/lib_arcade_qix.so";
    else if (input == 4)
        game = "./games/lib_arcade_solarfox.so";
    else if (input == 5)
        return;
    gHandl.loadLib(game);
    progloop(ste, hdl, gHandl);
}

int main(int ac, char **av)
{
    setlocale(LC_ALL, "");
    std::string libPath = ac == 2 ? av[1] : "nullptr";
    std::string game;

    if (libPath == "nullptr")
        return (84);
    printName();
    dlHandler hdl;
    hdl.loadLib(libPath);
    menu ste;
    hdl.getLib();
    game = ste.loop(hdl);
    game = "./games/" + game;
    if (game.find("nothing") != static_cast<long unsigned int> (-1))
        return (0);
    gameHandler gHandl;
    gHandl.loadLib(game);
    progloop(ste, hdl, gHandl);
    return (0);
}