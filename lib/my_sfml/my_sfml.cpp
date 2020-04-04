/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#include "my_sfml.hpp"

ILib *lib = nullptr;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arcade");

mySfml::mySfml()
{
    window.setFramerateLimit(60);
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

void mySfml::print(int y, int x, const std::string &s)
{
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));

    rectangle.setPosition(x, y);
    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == '#')
            window.draw(rectangle);
    }
}

int mySfml::getchw()
{
    int ret = 0;
    sf::Event event;

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