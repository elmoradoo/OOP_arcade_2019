/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** enemy
*/

#include "enemy.hpp"

enemy::enemy(std::string pos)
{
    if (pos == "top") {
        _sp = 'v';
        _x = 0;
        _y = 20;
        _heading = true;
    }
    else if (pos == "bottom") {
        _sp = '^';
        _x = 10;
        _y = 20;
    }
    else if (pos == "left") {
        _sp = '>';
        _x = 1;
        _y = 10;
        _side = true;
    }
    else if (pos == "right") {
        _sp = '<';
        _x = 39;
        _y = 10;
        _side = true;
        _heading = true;
    }
}

int enemy::getSp()
{
    return (_sp);
}
size_t enemy::getX()
{
    return (_x);
}
size_t enemy::getY()
{
    return (_y);
}

void enemy::compute()
{
    _x++;
    if (!_side && (_x == 1 || _y == 20))
        _heading = !_heading;
    
    // if (!_side)
        _x = _heading == true ? _x - 1 : _x + 1;
}