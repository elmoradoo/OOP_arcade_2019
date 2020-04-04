/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#ifndef MY_SFML_HPP_
#define MY_SFML_HPP_

#include "ILib.hpp"

class mySfml : public ILib
{
    private:
    public:
        mySfml();
        ~mySfml();
        void erasew() const;
        void refreshw() const;
        void print(int y, int x, const std::string &s) const;
        int getchw() const;
};

#endif /* !MY_SFML_HPP_ */
