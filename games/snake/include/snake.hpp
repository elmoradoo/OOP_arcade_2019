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

class snake_g {
    public:
        snake_g();
        virtual ~snake_g() = 0;
        virtual void render_map(std::vector<std::string>) = 0;
        virtual int check_if_lose(std::shared_ptr<snake_c>, int, std::vector<std::string>) = 0;
        virtual int move_snake(std::shared_ptr<snake_c>, int, std::vector<std::string>) = 0;
        virtual std::vector<std::string> put_snake_on_map(std::shared_ptr<snake_c>, std::vector<std::string>) = 0;
        virtual std::vector<std::string> create_map(void) = 0;
        virtual void close_game(void) = 0;
        virtual std::shared_ptr<snake_c> init_snake(void) = 0;
        virtual std::vector<std::string> put_fruit(std::vector<std::string>, std::shared_ptr<snake_c>) = 0;
        virtual void add_body_to_snake(std::shared_ptr<snake_c>, std::vector<std::string>) = 0;
        virtual std::vector<std::string> check_if_fruit(std::vector<std::string>, std::shared_ptr<snake_c>) = 0;
        virtual int change_speed(int) = 0;
        virtual void init_game(void) = 0;
        virtual int get_input(void) = 0;
    private:
};

int snake_game();

#endif /* !SNAKE_HPP_ */
