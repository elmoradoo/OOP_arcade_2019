/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#include "my_sfml.hpp"

ILib *lib = nullptr;

mySfml::mySfml()
{
    window.setFramerateLimit(60);
}

mySfml::~mySfml()
{
}

void mySfml::refreshw()
{
    window.display();
}

void mySfml::erasew()
{
    window.clear();
}

void mySfml::print(int y, int x, const std::string &s) const 
{
}

int mySfml::getchw() const
{
}

__attribute__((constructor)) void load_lib()
{
    lib = new mySfml();
}

// __attribute__((destructor)) void unload_lib()
// {
// }

extern "C" ILib *entry_point()
{
    return (lib);
}