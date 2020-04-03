/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include <ctime>
#include <vector>
#include <ncurses.h>
#include <sys/ioctl.h>
#include "IGame.hpp"
#include "ILib.hpp"

typedef struct pos_s {
    int x;
    int y;
} pos_t;

class snake_c {
    public:
        snake_c();
        snake_c(std::shared_ptr<snake_c>);
        ~snake_c();
        pos_t getPos(int) const;
        void setPos(pos_t, int);
        void setPosx(int x, int index);
        void setPosy(int, int);
        int getLength(void) const;
        std::vector<pos_t> getList(void) const;
        std::string getPrevious(void) const;
        void addElem(pos_t);
        void setLength(int);
        void setPrevious(const std::string &);
    private:
        int length;
        std::string previous_input;
        std::vector<pos_t> list;
};

class snake : public IGame {
    public:
        snake();
        void loop(ILib* lib);
        void render_map(std::vector<std::string>, std::shared_ptr<snake_c>, ILib *);
        int check_if_lose(std::shared_ptr<snake_c>, int, std::vector<std::string>);
        int move_snake(std::shared_ptr<snake_c>, int, std::vector<std::string>);
        std::vector<std::string> put_snake_on_map(std::shared_ptr<snake_c>, std::vector<std::string>);
        std::vector<std::string> create_map(void);
        std::shared_ptr<snake_c> init_snake(void);
        std::vector<std::string> put_fruit(std::vector<std::string>, std::shared_ptr<snake_c>);
        void add_body_to_snake(std::shared_ptr<snake_c>, std::vector<std::string>);
        std::vector<std::string> check_if_fruit(std::vector<std::string>, std::shared_ptr<snake_c>);
        int change_speed(int);
        int get_input(ILib *);
};

#endif /* !SNAKE_HPP_ */
