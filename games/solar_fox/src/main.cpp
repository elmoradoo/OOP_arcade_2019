/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "main.hpp"


int main()
{
    initscr();
    noecho();
    ngame game;
    keypad(stdscr, TRUE);
    curs_set(0);
    game.loadLevel("maps/map01.txt");
    while (1) {
        game.refreshWinSize();
        game.display();
        game.getInput();
        refresh();
    }
    endwin();
    return 0;
}

// UNE HEURE SEIZE