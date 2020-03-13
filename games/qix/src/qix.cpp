/*
** EPITECH PROJECT, 2020
** qix
** File description:
** qix
*/

#include "qix.hpp"

void qix::display()
{
    for (std::size_t i = 0; i != map.size(); i++)
        mvprintw(i, 0, map[i].c_str());
}

qix::qix()
{
    std::string str = "";

    for (int i = 0; i != 51; i++)
        str += "#";
    map.push_back(str);
    for (int i = 0; i != 51; i++) {
        str = "#";
        for (int j = 1; j != 50; j++)
            str += " ";
        str += "#";
        map.push_back(str);
    }
    str = "";
    for (int i = 0; i != 51; i++)
        str += "#";
    map.push_back(str);
}