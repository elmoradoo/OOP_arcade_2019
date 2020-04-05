/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#ifndef MY_SFML_HPP_
#define MY_SFML_HPP_

#include "ILib.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class mySfml : public ILib
{
    private:
        sf::RenderWindow window;
        sf::Event event;
        sf::Font font;
        sf::Text text;
        sf::RectangleShape white_rectangle;
        sf::RectangleShape red_rectangle;
        sf::RectangleShape little_white_rectangle1;
        sf::RectangleShape little_white_rectangle2;
        sf::RectangleShape yellow_rectangle;
        sf::RectangleShape black_rectangle;
        sf::RectangleShape brown_rectangle;
        sf::RectangleShape grey_rectangle;
        sf::RectangleShape orange_rectangle;
        sf::RectangleShape blue_rectangle;
    public:
        mySfml();
        ~mySfml();
        void erasew();
        void refreshw();
        void print(int y, int x, const std::string &s);
        void setSpeed(int speed);
        int getchw();
};

#endif /* !MY_SFML_HPP_ */
