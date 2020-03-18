/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake_class
*/

#include "snake.hpp"

snake_c::snake_c() : length(0), previous_input("LEFT"), list(NULL)
{
}

snake_c::~snake_c()
{
    list_t *temp = this->list;

    for (int i = 0; i < this->length; i++) {
        for (int j = 1; j < this->length - i; j++)
            temp = temp->next;
        delete (temp->next);
        temp = this->list;
    }
    delete (this->list);
}

pos_t snake_c::getPos() const
{
    return (this->list->pos);
}

int snake_c::getLength() const
{
    return (this->length);
}

void snake_c::setLength(int length)
{
    this->length = length;
}

list_t *snake_c::getList() const
{
    return (this->list);
}

void snake_c::setHead(list_t *new_list)
{
    this->list = new_list;
}

void snake_c::setHead(pos_t pos)
{
    list_t *new_list = new list_t;

    new_list->pos.x = pos.x;
    new_list->pos.y = pos.y;
    new_list->next = NULL;
    this->list = new_list;
}

void snake_c::addElem(pos_t pos)
{
    list_t *temp;
    list_t *new_list = new list_t;

    new_list->pos.x = pos.x;
    new_list->pos.y = pos.y;
    new_list->next = NULL;
    temp = this->list;
    for (int i = 0; i < this->length - 1; i++)
        temp = temp->next;
    temp->next = new_list;
}

std::string snake_c::getPrevious() const
{
    return (this->previous_input);
}

void snake_c::setPrevious(const std::string &new_str)
{
    this->previous_input = new_str;
}