/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "main.hpp"
#include "enemy.hpp"
struct coords
{
    size_t x = 0;
    size_t y = 0;
    char sp = '?';
    // std::unique_ptr<bulletT> b;
};

typedef struct coords entity;

struct bulletS
{
    size_t x = 0;
    size_t y = 0;
    size_t time = 0;
    bool player = false;
    char sp = '?';
};

typedef struct bulletS bulletT;

struct enemS
{
    int sp = '?';
    size_t x = 0;
    size_t y = 0;
    bool side = false;
    bool heading = false;
    // std::unique_ptr<bulletT> b;
};

typedef struct enemS enemT;

class ngame
{
public:
    ngame();
    ~ngame();
    std::vector<std::string> getMap();
    void display();
    void refreshWinSize();
    void refreshBoard();
    void getInput();
    void loadLevel(std::string level = "default");
    void addEnem(std::string pos);
    void computeEnem();
private:
    struct winsize _win;
    size_t _win_col;
    size_t _win_row;
    entity _player = {20, 10, 'O'};
    int _input;
    size_t _level = 0;
    size_t _points = 0;
    size_t _totalPoints = 10;
    std::vector<enemT> _enem;
    // std::vector<bulletT> _bullets;
    std::vector<std::string> _map;
    std::vector<std::string> _item_map;
    std::vector<std::string> _level_list  = { "maps/map01.txt",
                                              "maps/map02.txt"};
};

#endif /* !GAME_HPP_ */