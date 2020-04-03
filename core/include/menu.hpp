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
#include "ILib.hpp"
#include <memory>
#include <iostream>


class menu {
    private:
        int posx;
        int posy;
    public:
        menu(/* args */);
        ~menu();
        void Display(ILib * lib) const;
        std::string loop(ILib *lib);
        int interpreteInput(int input);
        int getPosx() const;
        int getPosy() const;
};


#endif /* !MENU_HPP_ */
