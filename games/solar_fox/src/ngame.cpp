/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ngame
*/

#include "ngame.hpp"

ngame::ngame()
{
    ioctl(0, TIOCGWINSZ, &_win);
    std::string str = "";

    for (int i = 0; i != 40; i++)
        str += "#";
    _map.push_back(str);
    for (int i = 0; i != 20; i++) {
        str = "#";
        for (int j = 1; j != 39; j++)
            str += " ";
        str += "#";
        _map.push_back(str);
    }
    str = "";
    for (int i = 0; i != 40; i++)
        str += "#";
    _map.push_back(str);
}

ngame::~ngame()
{

}

void ngame::loadLevel(std::string level)
{
    std::ifstream file(level, std::ios::in);
    std::string str = "";
    _totalPoints = 0;
    while (std::getline(file, str)) {
        _item_map.push_back(str);
    }
    for (std::size_t i = 0; i != _map.size(); i++)
        for (std::size_t j = 0; j != _map.at(i).size(); j++)
            if (_item_map.at(i).at(j) == 'X') {
                _map.at(i).at(j) = 'X';
                _totalPoints++;
            }
}

void ngame::refreshWinSize()
{
    _win_col = _win.ws_col;
    _win_row = _win.ws_row;
}

std::vector<std::string> ngame::getMap()
{
    return (_map);
}

void ngame::refreshBoard()
{
    if (_map.at(_player.y).at(_player.x) == 'X') {
        _map.at(_player.y).at(_player.x) = ' ';
        _points++;
    }
    _map.at(_player.y).at(_player.x) = _player.sp;
}

void ngame::getInput()
{
    _input = getch();

    if (_input == KEY_LEFT && _player.x > 1) {
        _map.at(_player.y).at(_player.x) = ' ';
        _player.x -= 1;
    }
    if (_input == KEY_RIGHT && _player.x <= 37) {
        _map.at(_player.y).at(_player.x) = ' ';
        _player.x += 1;
    }
    if (_input == KEY_UP && _player.y > 1) {
        _map.at(_player.y).at(_player.x) = ' ';
        _player.y -= 1;
    }
    if (_input == KEY_DOWN && _player.y < 20) {
        _map.at(_player.y).at(_player.x) = ' ';
        _player.y += 1;
    }
}
void ngame::display()
{
    this->refreshBoard();
    size_t i = 0;
    std::string formString = "SCORE [";
    for (; i != _map.size(); i++)
            mvprintw(i, 0, _map.at(i).c_str());
    i++;
    formString.append(std::to_string(_points));
    formString.append("/");
    formString.append(std::to_string(_totalPoints));
    formString.append("]");
    mvprintw(i, 0, formString.c_str());
    

    // mvprintw(0, 0, std::to_string(_win_col).c_str());
    // mvprintw(1, 0, std::to_string(_win_row).c_str());
    // for (std::size_t i = 0; i != _map.size(); i++)
    //     mvprintw(i/* +(_win_row / 2)*/,0 /*( _win_col / 2) - (_map.size() / 2)*/, _map[i].c_str());
}