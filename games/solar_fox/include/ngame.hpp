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

struct enemyS
{
    size_t x = 0;
    size_t y = 0;
    char sp = '?';
    bool hit = false;
    bool head = false;
};

typedef struct enemyS enn;

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
    void loadLevel(std::string level = "default");
private:
    struct winsize _win;
    size_t _win_col;
    size_t _win_row;
    entity _player = {20, 10, 'O'};
    int _input;
    size_t _level = 0;
    size_t _points = 0;
    size_t _totalPoints = 10;
    enn enem[3];
    std::vector<std::string> _map;
    std::vector<std::string> _item_map;
    std::vector<std::string> _level_list  = { "maps/map01.txt",
                                              "maps/map02.txt"};
};

#endif /* !GAME_HPP_ */