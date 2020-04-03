/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** dlHandler
*/

#ifndef DLHANDLER_HPP_
#define DLHANDLER_HPP_

#include <iostream>
#include <dlfcn.h>
#include "ILib.hpp"


class dlHandler {
    private:
        void *_handle = nullptr;
    public:
        dlHandler() = default;
        ~dlHandler() = default;
        void loadLib(std::string path);
        void unLoadLib();
        ILib *getLib() const;
};

#endif /* !DLHANDLER_HPP_ */