/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ILib
*/

#ifndef ILIB_HPP_
#define ILIB_HPP_

#include <string>

class ILib {
    public:
        virtual ~ILib() = 0;
        virtual void erasew() = 0;
        virtual void refreshw() = 0;
        virtual void print(int y, int x, const std::string &s) = 0;
        virtual int getchw() = 0;
        virtual void setSpeed(int speed) = 0;
    protected:
    private:
};

#endif /* !ILIB_HPP_ */
