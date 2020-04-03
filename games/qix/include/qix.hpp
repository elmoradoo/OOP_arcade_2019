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
#include <sys/utsname.h>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "ILib.hpp"
#include "IGame.hpp"

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

class qix : public IGame{
    public:
        qix();
        int interpreteInput(int input);
        void addEnnemies(int x, int y, std::string s);
        void ennemiesTurn(int x, std::size_t i);
        void addBoss();
        void ennemiesMove();
        void setBackground();
        void setGameover();
        void setFirework();
        bool checkBossPos(int nbx, int nby);
        void bossMovement();
        void changeMap();
        int countDistance(player tmp, bool t);
        void addNewBorder(std::size_t i, std::size_t j);
        void tmpplayerMove();
        int getScore() const;
        void incScore();
        std::vector<std::string> getGameover() const;
        std::vector<std::string> getMap() const;
        std::vector<std::string> getBackground() const;
        player getPlayer() const;
        boss getFirework();
        boss getBoss() const;
        player getTmpplayer() const;
        int getTmptime() const;
        std::vector<player> getEnnemies() const;
        void display(ILib *lib);
        void loop(ILib *lib);
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