/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "qix.hpp"

void qix_game(qix game)
{
    struct winsize w;
    int input = 0;

    while (1) {
        ioctl(0, TIOCGWINSZ, &w);   
        erase();
        game.ennemiesmove();
        game.display();
        refresh();
        input = game.interprete_input(getch());
        if (input == -1)
            break;
    }
}

int main()
{
    std::srand(std::time(nullptr));
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    timeout(300);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, 160, 160);
    init_pair(4, 220, 220);
    init_pair(5, 20, 20);
    init_pair(6, 130, 130);
    init_pair(7, 15, 15);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
    init_pair(9, 6, 6);
    qix game;
    qix_game(game);
    endwin();
    return (0);
}