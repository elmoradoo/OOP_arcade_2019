/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "ncurses.hpp"

int snake_game(snake_g *game)
{
    int score = 0;
    int input = 0;
    int speed = 750;
    std::shared_ptr<snake_c> snake(new snake_c());
    int **map = game->create_map();

    snake = game->init_snake(snake);
    game->init_game();
    game->put_fruit(map, snake);
    while ((input = game->get_input()) != 'q') {
        timeout(speed);
        if (game->move_snake(snake, input, map) == -1)
            break;
        score = game->check_if_fruit(map, snake, score);
        if (snake->getPos().x == 0 || snake->getPos().x == 9 || snake->getPos().y == 0 || snake->getPos().y == 39)
            break;
        game->put_snake_on_map(snake, map);
        if (game->render_map(map) == -1) {
            game->close_game(map);
            return (-1);
        }
        speed = game->change_speed(score);
    }
    game->close_game(map);
    return (score);
}

int main(void)
{
    int score = 0;
    snake_g *game = new snake_g_ncurses;

    std::srand(std::time(nullptr));
    score = snake_game(game);
    if (score == -1) {
        delete (game);
        return (84);
    }
    printf("YOUR SCORE IS %d.\n", score);
    delete (game);
    return (0);
}