/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "qix.hpp"

int interprete_input(int input)
{
    if (input == 'q')
        return (-1);
    return (0);
}

void qix_game(qix game)
{
    struct winsize w;
    int input = 0;

    while (1) {
        ioctl(0, TIOCGWINSZ, &w);   
        erase();
        game.display();
        refresh();
        input = interprete_input(getch());
        if (input == -1)
            break;
    }
}

int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    timeout(1000);
    keypad(stdscr, TRUE);
    qix game;
    qix_game(game);
    endwin();
    return (0);
}