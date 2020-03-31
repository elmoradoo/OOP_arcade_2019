/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "ncurses.hpp"

int snake_game(snake_g *game)
{
    int input = 0;
    int speed = 750;
    std::shared_ptr<snake_c> snake = game->init_snake();
    std::vector<std::string> map = game->create_map();

    game->init_game();
    map = game->put_fruit(map, snake);
    while ((input = game->get_input()) != 'q') {
        timeout(speed);
        if (game->move_snake(snake, input, map) == -1)
            break;
        if (snake->getPos(0).x == 0 || snake->getPos(0).x == 11 || snake->getPos(0).y == 0 || snake->getPos(0).y == 40)
            break;
        map = game->check_if_fruit(map, snake);
        map = game->put_snake_on_map(snake, map);
        game->render_map(map);
        speed = game->change_speed(snake->getLength() - 3);
    }
    game->close_game();
    return (snake->getLength() - 3);
}

int main(void)
{
    int score = 0;
    snake_g *game = new snake_g_ncurses;

    score = snake_game(game);
    if (score == -1) {
        delete (game);
        return (84);
    }
    printf("YOUR SCORE IS %d.\n", score);
    delete (game);
    return (0);
}