/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake_class
*/

#include "snake.hpp"

snake_c::snake_c() : length(0), previous_input("LEFT")
{
}

snake_c::~snake_c()
{
}

pos_t snake_c::getPos(int index) const
{
    return (this->list.at(index));
}

void snake_c::setPos(pos_t pos, int index)
{
    this->list[index] = pos;
}

void snake_c::setPosx(int x, int index)
{
    this->list[index].x = x;
}

void snake_c::setPosy(int y, int index)
{
    this->list[index].y = y;
}

int snake_c::getLength(void) const
{
    return (this->length);
}

std::vector<pos_t> snake_c::getList(void) const
{
    return (this->list);
}

void snake_c::addElem(pos_t pos)
{
    this->list.push_back(pos);
    this->length += 1;
}

std::string snake_c::getPrevious(void) const
{
    return (this->previous_input);
}

void snake_c::setPrevious(const std::string &new_str)
{
    this->previous_input = new_str;
}