/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** qix
*/

#ifndef QIX_HPP_
#define QIX_HPP_

#include <vector>
#include <string>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <sys/utsname.h>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>

struct player {
    std::string c = "0";
    int x = 50;
    int y = 51;
    int xb = 50;
    int yb = 51;
};

struct boss {
    int x = 47;
    int y = 23;
    std::vector<std::vector<std::string>> animeboss;
    std::size_t nb = 0;
};

struct counter {
    int x;
    int y;
    int nbo;
    int nbt;
};

class qix {
    public:
        qix();
        void display();
        int interprete_input(int input);
        void addEnnemies(int x, int y, std::string s);
        void ennemiesturn(int x, std::size_t i);
        void addboss();
        void ennemiesmove();
        void setbackground();
        void setgameover();
        void setfirework();
        bool checkbosspos(int nbx, int nby);
        void bossmovement();
        void changemap();
        int countdistance(player tmp, bool t);
        void addnewborder(std::size_t i, std::size_t j);
    private:
        std::vector<std::string> map;
        std::vector<std::string> background;
        std::vector<std::string> gameover;
        boss firework;
        player p;
        std::vector<player> ennemies;
        player tmpplayer;
        int tmptime;
        boss b;
        counter count;
        int score;
    protected:
};


#endif /* !QIX_HPP_ */