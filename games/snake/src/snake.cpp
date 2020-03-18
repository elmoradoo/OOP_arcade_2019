/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#include "snake.hpp"

int render_map(int **map)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 40; j++) {
            if (map[i][j] == 1)
                mvprintw(i, j, " ");
            else if (map[i][j] == 2)
                mvprintw(i, j, "-");
            else if (map[i][j] == 3)
                mvprintw(i, j, "|");
            else if (map[i][j] == 4)
                mvprintw(i, j, "+");
            else if (map[i][j] == 5)
                mvprintw(i, j, "*");
            else if (map[i][j] == 6)
                mvprintw(i, j, "O");
            else
                return (-1);
        }
        mvprintw(i, 40, " ");
    }
    return (0);
}

int check_if_lose(std::shared_ptr<snake_c> snake, int input, int **map)
{
    pos_t temp = snake->getPos();
    std::string previous = snake->getPrevious();

    if (input == KEY_UP && previous != "DOWN" && map[temp.x - 1][temp.y] == 5)
        return (-1);
    else if (input == KEY_DOWN && previous != "UP" && map[temp.x + 1][temp.y] == 5)
        return (-1);
    else if (input == KEY_LEFT && previous != "RIGHT" && map[temp.x][temp.y - 1] == 5)
        return (-1);
    else if (input == KEY_RIGHT && previous != "LEFT" && map[temp.x][temp.y + 1] == 5)
        return (-1);
    return (0);
}

int move_snake(std::shared_ptr<snake_c> snake, int input, int **map)
{
    list_t *head;
    list_t *list;
    pos_t pos;
    pos_t temp;
    std::string previous = snake->getPrevious();

    list = snake->getList();
    head = list;
    pos = list->pos;
    if (check_if_lose(snake, input, map) == -1)
        return (-1);
    else if (input == KEY_UP && previous != "DOWN") {
        list->pos.x -= 1;
        snake->setPrevious("UP");
    } else if (input == KEY_DOWN && previous != "UP") {
        list->pos.x += 1;
        snake->setPrevious("DOWN");
    } else if (input == KEY_LEFT && previous != "RIGHT") {
        list->pos.y -= 1;
        snake->setPrevious("LEFT");
    } else if (input == KEY_RIGHT  && previous != "LEFT") {
        list->pos.y += 1;
        snake->setPrevious("RIGHT");
    } else {
        if (previous == "UP")
            list->pos.x -= 1;
        else if (previous == "DOWN")
            list->pos.x += 1;
        else if (previous == "LEFT")
            list->pos.y -= 1;
        else if (previous == "RIGHT")
            list->pos.y += 1;
    }
    for (int i = 0; i < snake->getLength() - 1; i++) {
        list = list->next;
        temp = list->pos;
        list->pos = pos;
        pos = temp;
    }
    snake->setHead(head);
    return (0);
}

void put_snake_on_map(std::shared_ptr<snake_c> snake, int **map)
{
    list_t *temp = snake->getList();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 40; j++) {
            if (map[i][j] == 5)
                map[i][j] = 1;
        }
    }
    for (int i = 0; i < snake->getLength(); i++) {
        map[temp->pos.x][temp->pos.y] = 5;
        temp = temp->next;
    }
}

int **create_map()
{
    int **map = (int **) malloc(sizeof(int *) * 11);

    for (int i = 0; i < 10; i++) {
        map[i] = (int *) malloc(sizeof(int) * 41);
        for (int j = 0; j < 40; j++)
            map[i][j] = 1;
        map[i][40] = 0;
        map[i + 1] = NULL;
    }
    for (int i = 0; i < 40; i++) {
        map[0][i] = 2;
        map[9][i] = 2;
    }
    for (int i = 0; i < 10; i++) {
        map[i][39] = 3;
        map[i][0] = 3;
    }
    map[0][0] = 4;
    map[0][39] = 4;
    map[9][0] = 4;
    map[9][39] = 4;
    return (map);
}

void free_map(int **map)
{
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

std::shared_ptr<snake_c> init_snake(std::shared_ptr<snake_c> snake)
{
    pos_t pos = {5, 19};

    snake->setHead(pos);
    snake->setLength(1);
    pos.y += 1;
    snake->addElem(pos);
    snake->setLength(2);
    pos.y += 1;
    snake->addElem(pos);
    snake->setLength(3);
    return (snake);
}

void put_fruit(int **map, std::shared_ptr<snake_c> snake)
{
    list_t *temp = snake->getList();
    pos_t fruit_pos;

    fruit_pos.x = rand() % 9;
    fruit_pos.y = rand() % 39;
    if (fruit_pos.x == 0)
        fruit_pos.x += 1;
    if (fruit_pos.y == 0)
        fruit_pos.y += 1;
    for (int i = 0; i < snake->getLength(); i++) {
        if (fruit_pos.x == snake->getPos().x && fruit_pos.y == snake->getPos().y) {
            i = -1;
            temp = snake->getList();
            continue;
        }
        temp = temp->next;
    }
    map[fruit_pos.x][fruit_pos.y] = 6;
}

void add_body_to_snake(std::shared_ptr<snake_c> snake)
{
    pos_t new_pos;
    list_t *list = snake->getList();

    for (int i = 0; i < snake->getLength() - 2; i++)
        list = list->next;
    if (list->pos.x - list->next->pos.x < 0) {
        new_pos.x = list->next->pos.x + 1;
        new_pos.y = list->next->pos.y;
    } else if (list->pos.x - list->next->pos.x > 0) {
        new_pos.x = list->next->pos.x - 1;
        new_pos.y = list->next->pos.y;
    } else if (list->pos.y - list->next->pos.y > 0) {
        new_pos.x = list->next->pos.x;
        new_pos.y = list->next->pos.y - 1;
    } else if (list->pos.y - list->next->pos.y < 0) {
        new_pos.x = list->next->pos.x;
        new_pos.y = list->next->pos.y + 1;
    }
    snake->addElem(new_pos);
    snake->setLength(snake->getLength() + 1);
}

int check_if_fruit(int **map, std::shared_ptr<snake_c> snake, int score)
{
    if (map[snake->getPos().x][snake->getPos().y] == 6) {
        put_fruit(map, snake);
        add_body_to_snake(snake);
        return (score + 1);
    }
    return (score);
}

int change_speed(int score)
{
    if (score >= 20)
        return (650000);
    else if (score >= 40)
        return (550000);
    else if (score >= 60)
        return (450000);
    else if (score >= 80)
        return (350000);
    else if (score >= 100)
        return (200000);
    return (750000);
}

int snake_game()
{
    int score = 0;
    int input = 0;
    int speed = 750;
    std::shared_ptr<snake_c> snake(new snake_c());
    int **map = create_map();

    snake = init_snake(snake);
    put_fruit(map, snake);
    while ((input = getch()) != 'q') {
        timeout(speed);
        if (move_snake(snake, input, map) == -1)
            break;
        score = check_if_fruit(map, snake, score);
        if (snake->getPos().x == 0 || snake->getPos().x == 9 || snake->getPos().y == 0 || snake->getPos().y == 39)
            break;
        put_snake_on_map(snake, map);
        if (render_map(map) == -1) {
            free_map(map);
            return (-1);
        }
        refresh();
        speed = change_speed(score);
    }
    free_map(map);
    return (score);
}

void init_ncurses()
{
    initscr();
    noecho();
    curs_set(FALSE);
    timeout(1);
    keypad(stdscr, TRUE);
}

int main(void)
{
    int score = 0;

    srand(time(NULL));
    init_ncurses();
    score = snake_game();
    endwin();
    if (score == -1)
        return (84);
    printf("YOUR SCORE IS %d.\n", score);
    return (0);
}