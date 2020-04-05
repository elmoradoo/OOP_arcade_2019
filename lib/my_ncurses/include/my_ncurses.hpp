/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_ncurses
*/

#ifndef MY_NCURSES_HPP_
#define MY_NCURSES_HPP_

#include "ILib.hpp"
#include <ncurses.h>
#include <sys/ioctl.h>
#include <locale.h>

class myNcurses : public ILib
{
private:
public:
    myNcurses();
    ~myNcurses();
    void erasew();
    void refreshw();
    void print(int y, int x, const std::string &s);
    int getchw();
    void setSpeed(int speed);
};

#endif /* !MY_NCURSES_HPP_ */
