/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "ILib.hpp"
#include "IGame.hpp"

class pacman : public IGame {
    private:
    public:
        pacman();
        ~pacman();
        void loop(ILib *lib);
};

#endif /* !PACMAN_HPP_ */
