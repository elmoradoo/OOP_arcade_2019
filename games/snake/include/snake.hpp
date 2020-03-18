/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include <time.h>

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

int render_map(int **map);
int check_if_lose(std::shared_ptr<snake_c> snake, int input, int **map);
int move_snake(std::shared_ptr<snake_c> snake, int input, int **map);
void put_snake_on_map(std::shared_ptr<snake_c> snake, int **map);
int **create_map();
void free_map(int **map);
std::shared_ptr<snake_c> init_snake(std::shared_ptr<snake_c> snake);
void put_fruit(int **map, std::shared_ptr<snake_c> snake);
void add_body_to_snake(std::shared_ptr<snake_c> snake);
int check_if_fruit(int **map, std::shared_ptr<snake_c> snake, int score);
int change_speed(int score);
int snake_game();
void init_ncurses();

#endif /* !SNAKE_HPP_ */
