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
        str.append("#");
    _map.push_back(str);
    for (int i = 0; i!= 20; i++) {
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
    // _player.b->player = true;
}

ngame::~ngame() {}

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

void ngame::addEnem(std::string pos)
{
    enemT tmp;
    if (pos == "top") {
        tmp.sp = 'v';
        tmp.x = 20;
        tmp.y = 1;
        tmp.heading = true;
    }
    else if (pos == "bottom") {
        tmp.sp = '^';
        tmp.x = 10;
        tmp.y = 20;
    }
    else if (pos == "left") {
        tmp.sp = '>';
        tmp.x = 1;
        tmp.y = 10;
        tmp.side = true;
    }
    else if (pos == "right") {
        tmp.sp = '<';
        tmp.x = 38;
        tmp.y = 10;
        tmp.side = true;
        tmp.heading = true;
    }
    _enem.push_back(tmp);
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

void ngame::computeEnem()
{
    for (size_t i = 0; i < _enem.size(); i++) {
        if (_enem.at(i).sp == '^' || _enem.at(i).sp == 'v') {
            if (_enem.at(i).x == 38)
                _enem.at(i).heading = false;
            else if (_enem.at(i).x == 1)
                _enem.at(i).heading = true;
            if (_enem.at(i).heading == true) {
                _map.at(_enem.at(i).y).at(_enem.at(i).x) = ' ';
                _enem.at(i).x++;
            } else if (_enem.at(i).heading == false ) {
                _map.at(_enem.at(i).y).at(_enem.at(i).x) = ' ';
                _enem.at(i).x--;
            }
        } else if (_enem.at(i).sp == '>' || _enem.at(i).sp == '<') {
            if (_enem.at(i).y == 1)
                _enem.at(i).heading = true;
            else if (_enem.at(i).y == 20)
                _enem.at(i).heading = false;
            if (_enem.at(i).heading == true) {
                _map.at(_enem.at(i).y).at(_enem.at(i).x) = ' ';
                _enem.at(i).y++;
            } else if (_enem.at(i).heading == false ) {
                _map.at(_enem.at(i).y).at(_enem.at(i).x) = ' ';
                _enem.at(i).y--;
            }
        }
        _map.at(_enem.at(i).y).at(_enem.at(i).x) = _enem.at(i).sp;
    }
}

void ngame::refreshBoard()
{
    if (_map.at(_player.y).at(_player.x) == 'X') {
        _map.at(_player.y).at(_player.x) = ' ';
        _points++;
    }
    computeEnem();
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
    std::string debug = std::to_string(_enem.at(0).x);
    debug += "⛏";
    debug += std::to_string(_enem.at(0).y);
    mvprintw(i + 1, 0, debug.c_str());

    // mvprintw(0, 0, std::to_string(_win_col).c_str());
    // mvprintw(1, 0, std::to_string(_win_row).c_str());
    // for (std::size_t i = 0; i != _map.size(); i++)
    //     mvprintw(i/* +(_win_row / 2)*/,0 /*( _win_col / 2) - (_map.size() / 2)*/, _map[i].c_str());
}