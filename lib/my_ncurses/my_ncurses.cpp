/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_ncurses
*/

#include <iostream>
#include "my_ncurses.hpp"

ILib *lib = nullptr;

myNcurses::myNcurses()
{
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
}

myNcurses::~myNcurses()
{
    endwin();
}

void myNcurses::refreshw() const
{
    refresh();
}

void myNcurses::erasew() const
{
    erase();
}

void myNcurses::print(int y, int x, const std::string &s) const 
{
    mvprintw(y, x, s.c_str());
}

int myNcurses::getchw() const
{
    return (getch());
}

__attribute__((constructor)) void load_lib()
{
    lib = new myNcurses();
}

// __attribute__((destructor)) void unload_lib()
// {
// }

extern "C" ILib *entry_point()
{
    return (lib);
}