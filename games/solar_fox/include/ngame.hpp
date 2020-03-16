/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <ncurses.h>
#include "main.hpp"

struct coords
{
    size_t x = 0;
    size_t y = 0;
    char sp = '?';
};

typedef struct coords entity;

class ngame
{
public:
    ngame();
    ~ngame();
    void display();
    void refreshWinSize();
    void refreshBoard();
    void getInput();
    std::vector<std::string> getMap();
private:
    struct winsize _win;
    size_t _win_col;
    size_t _win_row;
    entity _player = {20, 10, 'O'};
    int _input;
    std::vector<std::string> _map;

};

#endif /* !GAME_HPP_ */