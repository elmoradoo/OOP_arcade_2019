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

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct list_s {
    pos_t pos;
    struct list_s *next;
} list_t;

class snake_c {
    public:
        snake_c();
        snake_c(std::shared_ptr<snake_c>);
        ~snake_c();
        pos_t getPos() const;
        int getLength() const;
        list_t *getList() const;
        void setHead(pos_t);
        void setHead(list_t *new_list);
        std::string getPrevious() const;
        void addElem(pos_t);
        void setLength(int);
        void setPrevious(const std::string &);
    private:
        int length;
        std::string previous_input;
        list_t *list;
};

class snake_g {
    public:
        snake_g();
        virtual ~snake_g() = 0;
        virtual int render_map(int **) = 0;
        virtual int check_if_lose(std::shared_ptr<snake_c>, int, int **) = 0;
        virtual int move_snake(std::shared_ptr<snake_c>, int, int **) = 0;
        virtual void put_snake_on_map(std::shared_ptr<snake_c>, int **) = 0;
        virtual int **create_map() = 0;
        virtual void close_game(int **) = 0;
        virtual std::shared_ptr<snake_c> init_snake(std::shared_ptr<snake_c>) = 0;
        virtual void put_fruit(int **, std::shared_ptr<snake_c>) = 0;
        virtual void add_body_to_snake(std::shared_ptr<snake_c>) = 0;
        virtual int check_if_fruit(int **, std::shared_ptr<snake_c>, int) = 0;
        virtual int change_speed(int) = 0;
        virtual void init_game() = 0;
        virtual int get_input() = 0;
    private:
};

int snake_game();

#endif /* !SNAKE_HPP_ */
