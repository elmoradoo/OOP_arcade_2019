/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game Handler
*/

#include "dlHandler.hpp"
#include "dlHandlerGame.hpp"

typedef IGame *(*entry_point)();

void gameHandler::loadLib(std::string path)
{
    if (_handle != nullptr)
        unLoadLib();
    path = "./" + path;
    _handle = dlopen(path.c_str(), RTLD_LAZY);
    if (_handle == nullptr)
        std::cerr << dlerror() << std::endl;
}

void gameHandler::unLoadLib()
{
    dlclose(_handle);
}

IGame *gameHandler::getLib() const
{
    IGame *lib = nullptr;
    void *tmp = nullptr;
    entry_point entry;
    if (_handle == nullptr) {
        std::cerr << "No lib has been loaded yet" << std::endl;
       exit(84);
    }
    tmp = dlsym(_handle, "entry_point");
    if (tmp == nullptr) {
        std::cerr << "Could not get Game Lib Class" << std::endl;
        exit(84);
    }
    entry = (entry_point)tmp;
    lib = entry();
    return (lib);
}