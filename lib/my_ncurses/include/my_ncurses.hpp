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

class myNcurses : public ILib
{
private:
public:
    myNcurses();
    ~myNcurses();
    void erasew() const;
    void refreshw() const;
    void print(int y, int x, const std::string &s) const;
    int getchw() const;
};

#endif /* !MY_NCURSES_HPP_ */
