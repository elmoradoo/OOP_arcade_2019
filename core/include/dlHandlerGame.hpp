/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** dlHandlerGame
*/

#ifndef DLHANDLERGAME_HPP_
#define DLHANDLERGAME_HPP_

#include "IGame.hpp"

class gameHandler {
    private:
        void *_handle = nullptr;
    public:
        gameHandler() = default;
        ~gameHandler() = default;
        void loadLib(std::string path);
        void unLoadLib();
        IGame *getLib() const;
};

#endif /* !DLHANDLERGAME_HPP_ */
