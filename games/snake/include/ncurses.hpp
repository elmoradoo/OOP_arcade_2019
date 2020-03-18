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
        ~snake_g_ncurses() override;
        int render_map(int **) override;
        int check_if_lose(std::shared_ptr<snake_c>, int, int **) override;
        int move_snake(std::shared_ptr<snake_c>, int, int **) override;
        void put_snake_on_map(std::shared_ptr<snake_c>, int **) override;
        int **create_map() override;
        void close_game(int **) override;
        std::shared_ptr<snake_c> init_snake(std::shared_ptr<snake_c>) override;
        void put_fruit(int **, std::shared_ptr<snake_c>) override;
        void add_body_to_snake(std::shared_ptr<snake_c>) override;
        int check_if_fruit(int **, std::shared_ptr<snake_c>, int) override;
        int change_speed(int) override;
        void init_game() override;
        int get_input() override;
    private:
};

#endif /* !NCURSES_HPP_ */
