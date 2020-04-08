/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "ILib.hpp"
#include "IGame.hpp"

class centipede : public IGame {
    private:
    public:
        centipede();
        ~centipede();
        int loop(dlHandler &hdl);
};

#endif /* !CENTIPEDE_HPP_ */
