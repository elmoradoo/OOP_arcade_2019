/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#include "my_sfml.hpp"

ILib *lib = nullptr;

mySfml::mySfml() : window(sf::VideoMode(1920, 1080), "Arcade")
{
    window.setFramerateLimit(23);
    window.setKeyRepeatEnabled(false);
}

mySfml::~mySfml()
{
}

void mySfml::refreshw()
{
    window.display();
}

void mySfml::erasew()
{
    window.clear();
}

void mySfml::setSpeed(int speed)
{
    if (speed == 0)
        window.setFramerateLimit(10);
    else if (speed == 1)
        window.setFramerateLimit(14);
    else if (speed == 2)
        window.setFramerateLimit(18);
    else if (speed == 3)
        window.setFramerateLimit(23);
}

void mySfml::print(int y, int x, const std::string &s)
{
    sf::RectangleShape white_rectangle(sf::Vector2f(10, 10));
    sf::RectangleShape red_rectangle(sf::Vector2f(10, 10));
    sf::Text text;
    white_rectangle.setFillColor(sf::Color(255, 255, 255));
    red_rectangle.setFillColor(sf::Color(255, 0, 0));

    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
        text.setCharacterSize(50);
        text.setString(s);
        text.setFillColor(sf::Color::Red);
        text.setPosition((x * 10), (y * 10));
        window.draw(text);
    } else {
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == '#' || s[i] == '*') {
                white_rectangle.setPosition(x + (i * 10), (y * 10));
                window.draw(white_rectangle);
            }
            else if (s[i] == '+') {
                red_rectangle.setPosition(x + (i * 10), (y * 10));
                window.draw(red_rectangle);
            }
        }
    }
}

int mySfml::getchw()
{
    int ret = 0;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            window.close();
            ret = 'e';
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            ret = 'z';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            ret = 'q';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            ret = 's';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            ret = 'd';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            ret = 'f';
        else
            ret = -1;
    }
    return (ret);
}

__attribute__((constructor)) void load_lib()
{
    lib = new mySfml();
}

// __attribute__((destructor)) void unload_lib()
// {
// }

extern "C" ILib *entry_point()
{
    return (lib);
}