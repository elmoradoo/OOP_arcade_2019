/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** menu
*/

#include "menu.hpp"

menu::menu(/* args */)
{
    posy = 0;
    posx = 0;
}

std::string menu::loop(ILib *lib)
{
    int input = 0;
    while (1) {
        lib->erasew();
        Display(lib);
        lib->refreshw();
        input = interpreteInput(lib->getchw());
        if (input == 'f') {
            if (this->posy == 0) // IF NIBBLER
                return ("lib_arcade_nibbler.so");
            else if (this->posy == 1) // IF QIX
                return("lib_arcade_qix.so");
            else if (this->posy == 2) // IF SOLARFOX
                return ("lib_arcade_solarfox.so");
        }
        if (input == -1)
            break;
    }
    return ("nothing");
}

void menu::Display(ILib * lib) const
{
    lib->print(7, 10, std::to_string(this->posx));
    lib->print(10, 10, "nibbler");
    lib->print(12, 10, "Qix");
    lib->print(14, 10, "Solar Fox");
    lib->print(7, 30, std::to_string(this->posy));
    lib->print(10, 30, "ncurse");
    lib->print(12, 30, "sfml");
    lib->print(14, 30, "open gl");
    lib->print(9 + (posy * 2), 9 + (posx * 20), "*************");
    lib->print(10 + (posy * 2), 9 + (posx * 20), "*");
    lib->print(10 + (posy * 2), 21 + (posx * 20), "*");
    lib->print(11 + (posy * 2), 9 + (posx * 20), "*************");
}

int menu::interpreteInput(int input)
{
    if (input == 'd' && posx != 1)
        posx++;
    if (input == 'q' && posx != 0)
        posx--;
    if (input == 's' && posy != 2)
        posy++;
    if (input == 'z' && posy != 0)
        posy--;
    if (input == 'e')
        return (-1);
    if (input == 'f')
        return ('f');
    return (0);
}

int menu::getPosx() const
{
    return (posx);
}

int menu::getPosy() const
{
    return (posy);
}

menu::~menu()
{
}