/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

// #include <vector>
#include <string>
#include <ncurses.h>
#include "ILib.hpp"
#include <sys/ioctl.h>
#include <memory>
#include <iostream>
#include <dlfcn.h>
// #include <sys/utsname.h>
// #include <algorithm>
// #include <fstream>
// #include <cstdlib>
// #include <iostream>
// #include <ctime>
// #include <unistd.h>

void qixRenderGame(qix &q);

class menu {
    private:
        int posx;
        int posy;
    public:
        menu(/* args */);
        ~menu();
        void Display() const;
        int interpreteInput(int input);
        int getPosx() const;
        int getPosy() const;
};


#endif /* !MENU_HPP_ */
