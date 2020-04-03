/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#include "snake.hpp"

int snake_game(ILib* lib)
{
    int input = 0;
    int speed = 750;
    std::shared_ptr<snake_c> snake = init_snake();
    std::vector<std::string> map = create_map();

    map = put_fruit(map, snake);
    while ((input = get_input(lib)) != 'q') {
        timeout(speed);
        if (move_snake(snake, input, map) == -1)
            break;
        if (snake->getPos(0).x == 0 || snake->getPos(0).x == 11 || snake->getPos(0).y == 0 || snake->getPos(0).y == 40)
            break;
        map = check_if_fruit(map, snake);
        map = put_snake_on_map(snake, map);
        render_map(map, snake, lib);
        speed = change_speed(snake->getLength() - 3);
    }
    return (snake->getLength() - 3);
}

void render_map(std::vector<std::string> map, std::shared_ptr<snake_c> snake, ILib *lib)
{
    unsigned int i = 0;
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    lib->erasew();
    if (w.ws_row < 10 || w.ws_col < 40)
        lib->print(w.ws_row / 2, w.ws_col / 2 - 9, "The map is too big");
    for (i = 0; i < map.size(); i++)
        lib->print(w.ws_row / 2 + i - 6, w.ws_col / 2 - 21, map[i].c_str());
    lib->print(w.ws_row / 2 + map.size() + 5, w.ws_col / 2, "SCORE: ");
    lib->print(w.ws_row / 2 + map.size() + 13, w.ws_col / 2, std::to_string(snake->getLength() - 3));
    lib->refreshw();
}

int check_if_lose(std::shared_ptr<snake_c> snake, int input, std::vector<std::string> map)
{
    pos_t pos_0 = snake->getPos(0);
    std::string previous = snake->getPrevious();

    if (input == KEY_UP && previous != "DOWN" && map[pos_0.x - 1][pos_0.y] == '*')
        return (-1);
    else if (input == KEY_DOWN && previous != "UP" && map[pos_0.x + 1][pos_0.y] == '*')
        return (-1);
    else if (input == KEY_LEFT && previous != "RIGHT" && map[pos_0.x][pos_0.y - 1] == '*')
        return (-1);
    else if (input == KEY_RIGHT && previous != "LEFT" && map[pos_0.x][pos_0.y + 1] == '*')
        return (-1);
    return (0);
}

int move_snake(std::shared_ptr<snake_c> snake, int input, std::vector<std::string> map)
{
    pos_t previous_pos = snake->getPos(0);
    pos_t temp;
    std::string previous = snake->getPrevious();

    if (check_if_lose(snake, input, map) == -1)
        return (-1);
    else if (input == KEY_UP && previous != "DOWN") {
        snake->setPosx(previous_pos.x - 1, 0);
        snake->setPrevious("UP");
    } else if (input == KEY_DOWN && previous != "UP") {
        snake->setPosx(previous_pos.x + 1, 0);
        snake->setPrevious("DOWN");
    } else if (input == KEY_LEFT && previous != "RIGHT") {
        snake->setPosy(previous_pos.y - 1, 0);
        snake->setPrevious("LEFT");
    } else if (input == KEY_RIGHT  && previous != "LEFT") {
        snake->setPosy(previous_pos.y + 1, 0);
        snake->setPrevious("RIGHT");
    } else {
        if (previous == "UP")
            snake->setPosx(previous_pos.x - 1, 0);
        else if (previous == "DOWN")
            snake->setPosx(previous_pos.x + 1, 0);
        else if (previous == "LEFT")
            snake->setPosy(previous_pos.y - 1, 0);
        else if (previous == "RIGHT")
            snake->setPosy(previous_pos.y + 1, 0);
    }
    for (int i = 1; i < snake->getLength(); i++) {
        temp = snake->getPos(i);
        snake->setPos(previous_pos, i);
        previous_pos = temp;
    }
    return (0);
}

std::vector<std::string> put_snake_on_map(std::shared_ptr<snake_c> snake, std::vector<std::string> map)
{
    for (unsigned int i = 0; i < map.size(); i++) {
        for (unsigned int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '*')
                map[i][j] = ' ';
        }
    }
    for (unsigned int i = 0; i < snake->getList().size(); i++)
        map[snake->getPos(i).x][snake->getPos(i).y] = '*';
    return (map);
}

std::vector<std::string> create_map(void)
{
    std::vector<std::string> map;

    map.push_back("+---------------------------------------+");
    for (int i = 0; i < 10; i++)
        map.push_back("|                                       |");
    map.push_back("+---------------------------------------+");
    return (map);
}

std::shared_ptr<snake_c> init_snake(void)
{
    std::shared_ptr<snake_c> snake(new snake_c);
    pos_t pos = {5, 19};

    snake->addElem(pos);
    pos.y += 1;
    snake->addElem(pos);
    pos.y += 1;
    snake->addElem(pos);
    return (snake);
}

std::vector<std::string> put_fruit(std::vector<std::string> map, std::shared_ptr<snake_c> snake)
{
    pos_t fruit_pos;

    fruit_pos.x = rand() % 8 + 1;
    fruit_pos.y = rand() % 38 + 1;
    for (int i = 0; i < snake->getLength(); i++) {
        if (fruit_pos.x == snake->getPos(i).x && fruit_pos.y == snake->getPos(i).y) {
            fruit_pos.x = rand() % 9 + 1;
            fruit_pos.y = rand() % 39 + 1;
            i = 0;
            continue;
        }
    }
    map[fruit_pos.x][fruit_pos.y] = 'O';
    return (map);
}

void add_body_to_snake(std::shared_ptr<snake_c> snake, std::vector<std::string> map)
{
    pos_t new_pos;

    if (snake->getPos(snake->getLength() - 2).x - snake->getPos(snake->getLength() - 1).x < 0) {
        new_pos.x = snake->getPos(snake->getLength() - 1).x + 1;
        new_pos.y = snake->getPos(snake->getLength() - 1).y;
    } else if (snake->getPos(snake->getLength() - 2).x - snake->getPos(snake->getLength() - 1).x > 0) {
        new_pos.x = snake->getPos(snake->getLength() - 1).x - 1;
        new_pos.y = snake->getPos(snake->getLength() - 1).y;
    } else if (snake->getPos(snake->getLength() - 2).y - snake->getPos(snake->getLength() - 1).y > 0) {
        new_pos.x = snake->getPos(snake->getLength() - 1).x;
        new_pos.y = snake->getPos(snake->getLength() - 1).y - 1;
    } else if (snake->getPos(snake->getLength() - 2).y - snake->getPos(snake->getLength() - 1).y < 0) {
        new_pos.x = snake->getPos(snake->getLength() - 1).x;
        new_pos.y = snake->getPos(snake->getLength() - 1).y + 1;
    }
    if (map[new_pos.x][new_pos.y] == '|') {
        new_pos.x = snake->getPos(snake->getLength() - 1).x;
        if (map[new_pos.x][new_pos.y - 1] != '-')
            new_pos.y -= 1;
        else
            new_pos.y += 1;
    } else if (map[new_pos.x][new_pos.y] == '-') {
        new_pos.y = snake->getPos(snake->getLength() - 1).y;
        if (map[new_pos.x - 1][new_pos.y] != '-')
            new_pos.y -= 1;
        else
            new_pos.y += 1;
    }
    snake->addElem(new_pos);
}

std::vector<std::string> check_if_fruit(std::vector<std::string> map, std::shared_ptr<snake_c> snake)
{
    if (map[snake->getPos(0).x][snake->getPos(0).y] == 'O') {
        add_body_to_snake(snake, map);
        map = put_fruit(map, snake);
    }
    return (map);
}

int change_speed(int score)
{
    if (score >= 20)
        return (650);
    else if (score >= 40)
        return (550);
    else if (score >= 60)
        return (450);
    else if (score >= 80)
        return (350);
    else if (score >= 100)
        return (200);
    return (750);
}

int get_input(ILib *lib)
{
    return (lib->getchw());
}