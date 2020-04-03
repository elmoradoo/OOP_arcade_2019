/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** menu
*/

#include "menu.hpp"

menu::menu(/* args */)
{
    posy = 0;
    posx = 0;
}

void menu::Display() const
{
    mvprintw(7, 10, "GAMES:");
    mvprintw(10, 10, "nibbler");
    mvprintw(12, 10, "Qix");
    mvprintw(14, 10, "Solar Fox");
    mvprintw(7, 30, "LIBS:");
    mvprintw(10, 30, "ncurse");
    mvprintw(12, 30, "sfml");
    mvprintw(14, 30, "open gl");
    mvprintw(9 + (posy * 2), 9 + (posx * 20), "*************");
    mvprintw(10 + (posy * 2), 9 + (posx * 20), "*");
    mvprintw(10 + (posy * 2), 21 + (posx * 20), "*");
    mvprintw(11 + (posy * 2), 9 + (posx * 20), "*************");
}

int menu::interpreteInput(int input)
{
    if (input == 'd' && posx != 1)
        posx++;
    if (input == 'q' && posx != 0)
        posx--;
    if (input == 's' && posy != 2)
        posy++;
    if (input == 'z' && posy != 0)
        posy--;
    if (input == 'e')
        return (-1);
    return (0);
}

int menu::getPosx() const
{
    return (posx);
}

int menu::getPosy() const
{
    return (posy);
}

menu::~menu()
{
}