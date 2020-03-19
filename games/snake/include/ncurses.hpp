/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <sys/ioctl.h>
#include "snake.hpp"

class snake_g_ncurses : public snake_g {
    public:
        snake_g_ncurses();
        ~snake_g_ncurses();
        void render_map(std::vector<std::string>);
        int check_if_lose(std::shared_ptr<snake_c>, int, std::vector<std::string>);
        int move_snake(std::shared_ptr<snake_c>, int, std::vector<std::string>);
        std::vector<std::string> put_snake_on_map(std::shared_ptr<snake_c>, std::vector<std::string>);
        std::vector<std::string> create_map(void);
        void close_game(void);
        std::shared_ptr<snake_c> init_snake(void);
        std::vector<std::string> put_fruit(std::vector<std::string>, std::shared_ptr<snake_c>);
        void add_body_to_snake(std::shared_ptr<snake_c>, std::vector<std::string>);
        std::vector<std::string> check_if_fruit(std::vector<std::string>, std::shared_ptr<snake_c>);
        int change_speed(int);
        void init_game(void);
        int get_input(void);
    private:
};

#endif /* !NCURSES_HPP_ */
