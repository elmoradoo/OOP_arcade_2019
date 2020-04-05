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
    
    initscr();
    noecho();
    timeout(500);
    keypad(stdscr, TRUE);
    curs_set(0);
    ngame game;
    // while (1)
    //     game.display();
    // while (1) {
    //     game.refreshWinSize();
    //     game.display();
    //     game.getInput();
    //     refresh();
    // }
    endwin();
    return 0;
}

// UNE HEURE SEIZE