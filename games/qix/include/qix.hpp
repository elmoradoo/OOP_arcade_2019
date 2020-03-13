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
#include <iostream>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <sys/utsname.h>

class qix {
    public:
        qix();
        void display();
    private:
        std::vector<std::string> map;
    protected:
};


#endif /* !QIX_HPP_ */
