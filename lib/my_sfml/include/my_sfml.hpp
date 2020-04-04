/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#ifndef MY_SFML_HPP_
#define MY_SFML_HPP_

#include "ILib.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class mySfml : public ILib
{
    private:
        sf::RenderWindow window;
    public:
        mySfml();
        ~mySfml();
        void erasew();
        void refreshw();
        void print(int y, int x, const std::string &s);
        int getchw();
};

#endif /* !MY_SFML_HPP_ */
