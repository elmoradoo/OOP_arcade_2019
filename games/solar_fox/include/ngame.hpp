/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
#define _XOPEN_SOURCE_EXTENDED
#include <memory>
#include <unistd.h>
#include <vector>

#include <iostream>
#include <fstream>

#include <sys/ioctl.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <locale.h>

#include "IGame.hpp"
#include "ILib.hpp"

struct bulletS
{
    size_t x = 0;
    size_t y = 0;
    int time = 0;
    bool player = false;
    char sp = '?';
    char head = '?';
};

typedef struct bulletS bulletT;

struct coords
{
    size_t x = 0;
    size_t y = 0;
    int bulletID = -1;
    char sp = '?';
};

typedef struct coords entity;

struct enemS
{
    int sp = '?';
    size_t x = 0;
    size_t y = 0;
    size_t bulletID = -1;
    bool side = false;
    bool heading = false;
};

typedef struct enemS enemT;

class ngame : public IGame
{
public:
    ngame();
    ~ngame();
    std::vector<std::string> getMap();
    void loop(dlHandler &hdl);
    void display();
    void refreshWinSize();
    void refreshBoard();
    void getInput(dlHandler hdl);
    void loadLevel(std::string level = "default");
    void addEnem(std::string pos);
    void computeEnem();
    void computeBullets();
    void resetBullet(size_t ID);
private:
    struct winsize _win;
    size_t _win_col;
    size_t _win_row;
    entity _player ;//= {20, 10, 'O'};
    int _input;
    size_t _level = 0;
    size_t _points = 0;
    size_t _totalPoints = 10;
    size_t _pv = 3;
    std::vector<enemT> _enem;
    std::vector<bulletT> _bullets;
    std::vector<std::string> _map;
    std::vector<std::string> _item_map;
    std::vector<std::string> _level_list  = { "maps/map01.txt",
                                              "maps/map02.txt"};
};

#endif /* !GAME_HPP_ */