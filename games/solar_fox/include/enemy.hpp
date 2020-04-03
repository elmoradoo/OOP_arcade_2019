/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "main.hpp"

class enemy
{
public:
    enemy(std::string pos);
    ~enemy() = default;
    int getSp();
    size_t getX();
    size_t getY();
    void compute();
private:
    int _sp = '?';
    size_t _x = 0;
    size_t _y = 0;
    bool _side = false;
    bool _heading = false;
};


#endif /* !ENEMY_HPP_ */
