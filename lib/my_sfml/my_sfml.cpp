/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#include "my_sfml.hpp"

ILib *lib = nullptr;

mySfml::mySfml() : window(sf::VideoMode(1920, 1080), "Arcade"), white_rectangle(sf::Vector2f(10, 10)), red_rectangle(sf::Vector2f(10, 10)), little_white_rectangle1(sf::Vector2f(5, 5)), little_white_rectangle2(sf::Vector2f(3, 15)), yellow_rectangle(sf::Vector2f(10, 10)), black_rectangle(sf::Vector2f(10, 10)), brown_rectangle(sf::Vector2f(10, 10)), grey_rectangle(sf::Vector2f(10, 10)), orange_rectangle(sf::Vector2f(10, 10)), blue_rectangle(sf::Vector2f(10, 10))
{
    white_rectangle.setFillColor(sf::Color(255, 255, 255));
    red_rectangle.setFillColor(sf::Color(255, 0, 0));
    little_white_rectangle1.setFillColor(sf::Color(255, 255, 255));
    little_white_rectangle2.setFillColor(sf::Color(255, 255, 255));
    yellow_rectangle.setFillColor(sf::Color::Yellow);
    black_rectangle.setFillColor(sf::Color::Black);
    brown_rectangle.setFillColor(sf::Color(88, 41, 0));
    grey_rectangle.setFillColor(sf::Color(100, 100, 100));
    orange_rectangle.setFillColor(sf::Color(255, 146, 17));
    blue_rectangle.setFillColor(sf::Color::Blue);
    font.loadFromFile("./font/Roboto-Thin.ttf");
    text.setFont(this->font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    window.setFramerateLimit(23);
    window.setKeyRepeatEnabled(false);
}

mySfml::~mySfml()
{
    window.close();
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
    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= '0' && s[0] <= '9')) {
        this->text.setString(s);
        this->text.setPosition((x * 10), (y * 10));
        window.draw(text);
    } else {
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == '#' || s[i] == '*') {
                this->white_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->white_rectangle);
            } else if (s[i] == '+') {
                this->red_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->red_rectangle);
            } else if (s[i] == ' ') {
                this->black_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->black_rectangle);
            } else if (s[i] == '&') {
                this->brown_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->brown_rectangle);
            } else if (s[i] == '"') {
                this->grey_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->grey_rectangle);
            } else if (s[i] == ')') {
                this->orange_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->orange_rectangle);
            } else if (s[i] == '(') {
                this->blue_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->blue_rectangle);
            } else if (s[i] == '=') {
                this->little_white_rectangle1.setPosition((x + i) * 5, (y * 10));
                window.draw(this->little_white_rectangle1);
            } else if (s[i] == '|') {
                this->little_white_rectangle2.setPosition((x + i) * 5, (y * 10));
                window.draw(this->little_white_rectangle2);
            } else {
                this->yellow_rectangle.setPosition((x + i) * 10, (y * 10));
                window.draw(this->yellow_rectangle);
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
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            ret = 'l';
        else
            ret = -1;
    }
    return (ret);
}

__attribute__((constructor)) void load_lib()
{
    lib = new mySfml();
}

/*__attribute__((destructor)) void unload_lib()
{
    delete lib;
}*/

extern "C" ILib *entry_point()
{
    return (lib);
}