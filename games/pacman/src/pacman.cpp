/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#include "pacman.hpp"

IGame *game = nullptr;

__attribute__((constructor)) void load_lib()
{
    game = new pacman;
}

// __attribute__((destructor)) void unload_lib()
// {
// }

extern "C" IGame *entry_point()
{
    return (game);
}

pacman::pacman()
{

}

pacman::~pacman()
{

}

void pacman::loop(ILib *lib)
{
    std::string s = "pacman";

    while (1) {
        lib->erasew();
        lib->print(10, 10, s);
        lib->refreshw();
    }
}