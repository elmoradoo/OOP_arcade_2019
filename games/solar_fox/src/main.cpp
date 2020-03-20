/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "main.hpp"
#include "ngame.hpp"
#include "enemy.hpp"

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    timeout(500);
    ngame game;
    game.addEnem("top");
    game.addEnem("bottom");
    game.addEnem("right");
    game.addEnem("left");
    // enemy enn("top");
    keypad(stdscr, TRUE);
    curs_set(0);
    game.loadLevel("maps/map01.txt");
    // int test = L'▼';
    // std::string tmp = "AAA";
    // std::string aa = "hello";
    // aa.append("▼");
    // aa.append("no");
    // aa[1] = '▼';
    // tmp += test;
    while (1) {
        // mvprintw(30,50, aa.c_str()); 
        // mvprintw(31,50, tmp.c_str()); 
        game.refreshWinSize();
        game.display();
        game.getInput();
        refresh();
    }
    endwin();
    return 0;
}

// UNE HEURE SEIZE