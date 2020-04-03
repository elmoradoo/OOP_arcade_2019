/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
#include "ILib.hpp"

class IGame {
    public:
        virtual void loop(ILib *lib) = 0;
    protected:
    private:
};

#endif /* !IGAME_HPP_ */
