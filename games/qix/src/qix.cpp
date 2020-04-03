/*
** EPITECH PROJECT, 2020
** qix
** File description:
** qix
*/

#include "qix.hpp"

void qix::loop(ILib *lib)
{
    while (1) { 
        lib->erasew();
        ennemiesMove();
        display(lib);
        lib->refreshw();
        if (interpreteInput(getch()) == -1)
            break;
    }
}


void qix::ennemiesTurn(int x, std::size_t i)
{
    if (x != 0)
        ennemies[i].y = ((ennemies[i].y - 1 > -1) && (map[ennemies[i].y - 1][ennemies[i].x] == '#') ? ennemies[i].y - 1 : ennemies[i].y + 1);
    else
        ennemies[i].x = ((ennemies[i].x - 1 > -1) && (map[ennemies[i].y][ennemies[i].x - 1] == '#') ? ennemies[i].x - 1 : ennemies[i].x + 1);
}

void qix::ennemiesMove()
{
    int x = 0;
    int y = 0;

    if (tmptime > 20) {
        x = tmpplayer.xb;
        y = tmpplayer.yb;
        tmpplayer.xb = tmpplayer.x;
        tmpplayer.yb = tmpplayer.y;
        if ((tmpplayer.x - x) < 0 && (tmpplayer.x - 1) > -1 && map[tmpplayer.y][tmpplayer.x - 1] == '*')
            tmpplayer.x--;
        else if ((tmpplayer.x - x) > 0 && (tmpplayer.x + 1) < 102 && map[tmpplayer.y][tmpplayer.x + 1] == '*')
            tmpplayer.x++;
        else if ((tmpplayer.y - y) < 0 && (tmpplayer.y - 1) > -1 && map[tmpplayer.y - 1][tmpplayer.x] == '*')
            tmpplayer.y--;
        else if ((tmpplayer.y - y) > 0 && (tmpplayer.y + 1) < 52 && map[tmpplayer.y + 1][tmpplayer.x] == '*')
            tmpplayer.y++;
        else {
            if ((tmpplayer.x - x) != 0)
                tmpplayer.y = ((tmpplayer.y - 1 > -1) && (map[tmpplayer.y - 1][tmpplayer.x] == '*') ? tmpplayer.y - 1 : tmpplayer.y + 1);
            else
                tmpplayer.x = ((tmpplayer.x - 1 > -1) && (map[tmpplayer.y][tmpplayer.x - 1] == '*') ? tmpplayer.x - 1 : tmpplayer.x + 1);
        }
    }
    for (std::size_t i = 0; i != ennemies.size(); i++) {
        if (map[ennemies[i].y][ennemies[i].x] != '#')
            continue;
        x = ennemies[i].xb;
        y = ennemies[i].yb;
        ennemies[i].xb = ennemies[i].x;
        ennemies[i].yb = ennemies[i].y;
        if ((ennemies[i].x - x) < 0 && (ennemies[i].x - 1) > -1 && map[ennemies[i].y][ennemies[i].x - 1] == '#')
            ennemies[i].x--;
        else if ((ennemies[i].x - x) > 0 && (ennemies[i].x + 1) < 102 && map[ennemies[i].y][ennemies[i].x + 1] == '#')
            ennemies[i].x++;
        else if ((ennemies[i].y - y) < 0 && (ennemies[i].y - 1) > -1 && map[ennemies[i].y - 1][ennemies[i].x] == '#')
            ennemies[i].y--;
        else if ((ennemies[i].y - y) > 0 && (ennemies[i].y + 1) < 52 && map[ennemies[i].y + 1][ennemies[i].x] == '#')
            ennemies[i].y++;
        else
            ennemiesTurn((ennemies[i].x - x), i);
    }
}

int qix::interpreteInput(int input)
{
    p.xb = p.x;
    p.yb = p.y;
    if (input == 'z' && p.y != 0 && map[p.y - 1][p.x] != '*' && map[p.y - 1][p.x] != 'a')
        p.y--;
    if (input == 's' && p.y < 51 && map[p.y + 1][p.x] != '*' && map[p.y + 1][p.x] != 'a')
        p.y++;
    if (input == 'q' && p.x != 0 && map[p.y][p.x - 1] != '*' && map[p.y][p.x - 1] != 'a')
        p.x--;
    if (input == 'd' && p.x < 101 && map[p.y][p.x + 1] != '*' && map[p.y][p.x + 1] != 'a')
        p.x++;
    if (input == 'e' || firework.nb == firework.animeboss.size() - 1)
        return (-1);
    if (map[p.y][p.x] == ' ' && map[p.yb][p.xb] == '#') {
        count.x = p.xb;
        count.y = p.yb;
    }
    for (std::size_t i = 0; i != ennemies.size(); i++)
        if (ennemies[i].x == p.x && ennemies[i].y == p.y)
            score = -1;
    if (tmpplayer.x == p.x && tmpplayer.y == p.y && tmptime > 20)
            score = -1;
    return (0);
}

int qix::countDistance(player tmp, bool t)
{
    int nb = 0;
    int x = 0;
    int y = 0;

    for (; tmp.x != p.x || tmp.y != p.y; nb++) {
        if (nb != 0 && t)
            map[tmp.y][tmp.x] = 'a';
        x = tmp.xb;
        y = tmp.yb;
        tmp.xb = tmp.x;
        tmp.yb = tmp.y;
        if ((tmp.x - x) < 0 && (tmp.x - 1) > -1 && map[tmp.y][tmp.x - 1] == '#')
            tmp.x--;
        else if ((tmp.x - x) > 0 && (tmp.x + 1) < 102 && map[tmp.y][tmp.x + 1] == '#')
            tmp.x++;
        else if ((tmp.y - y) < 0 && (tmp.y - 1) > -1 && map[tmp.y - 1][tmp.x] == '#')
            tmp.y--;
        else if ((tmp.y - y) > 0 && (tmp.y + 1) < 52 && map[tmp.y + 1][tmp.x] == '#')
            tmp.y++;
        else {
            x = tmp.x - x;
            if (x != 0)
                tmp.y = ((tmp.y - 1 > -1) && (map[tmp.y - 1][tmp.x] == '#') ? tmp.y - 1 : tmp.y + 1);
            else
                tmp.x = ((tmp.x - 1 > -1) && (map[tmp.y][tmp.x - 1] == '#') ? tmp.x - 1 : tmp.x + 1);
        }
    }
    return (nb);
}

void qix::changeMap()
{
    player tmp;
    player tmpbis;
    int s = 0;

    tmp.x = count.x;
    tmp.y = count.y;
    tmp.xb = count.x;
    tmp.yb = count.y;
    tmpbis = tmp;
    if ((tmp.x - 1) >= 0 && map[tmp.y][tmp.x - 1] == '#') {
        tmp.xb--;
        s = 1;
    } if ((tmp.x + 1) <= 101 && map[tmp.y][tmp.x + 1] == '#') {
        if (s != 1)
            tmp.xb++;
        else
            tmpbis.xb++;
        s = 1;
    } if ((tmp.y - 1) >= 0 && map[tmp.y - 1][tmp.x] == '#') {
        if (s != 1)
            tmp.yb--;
        else
            tmpbis.yb--;
        s = 1;
    } if ((tmp.y + 1) <= 51 && map[tmp.y + 1][tmp.x] == '#')
        tmpbis.yb++;
    count.nbo = countDistance(tmp, false);
    count.nbt = countDistance(tmpbis, false);
    if (count.nbo < count.nbt)
        countDistance(tmp, true);
    else
        countDistance(tmpbis, true);
    for (std::size_t i = 0; i != map.size(); i++)
        std::replace( map[i].begin(), map[i].end(), '*', '#');
    for (std::size_t i = 0; i != map.size(); i++)
        for (std::size_t j = 0; j != map[i].length(); j++) {
            if (map[i][j] == 'a')
                addNewBorder(i, j);        
        }
}

void qix::addNewBorder(std::size_t i, std::size_t j)
{
    if (j > 0 && map[i][j - 1] == ' ') {
        map[i][j - 1] = 'a';
        addNewBorder(i, j-1);
    } if ((j + 1) < map[i].length() && map[i][j + 1] == ' ') {
        map[i][j + 1] = 'a';
        addNewBorder(i, j+1);
    } if (i > 0 && map[i - 1][j] == ' ') {
        map[i - 1][j] = 'a';
        addNewBorder(i-1, j);
    } if ((i + 1) < map.size() && map[i + 1][j] == ' ') {
        map[i + 1][j] = 'a';
        addNewBorder(i+1, j);
    }
}

bool qix::checkBossPos(int nbx, int nby)
{
    for (int i = 0; i != 7; i++) 
        if (map[b.y + i][b.x + nbx] == '#')
            return (false);
    for (int i = 0; i != 10; i++) 
        if (map[b.y + nby][b.x + i] == '#')
            return (false);
    return (true);
}

void qix::setGameover()
{
    std::ifstream _file("gameover", std::ios::in);
    std::string buffer;

    while (std::getline(_file, buffer, '\n'))
        gameover.push_back(buffer);
}

void qix::bossMovement()
{
    int nb = std::rand()%4+1;

    b.nb++;
    if (b.nb == b.animeboss.size())
        b.nb = 0;
    if (nb == 1 && (b.x + 9) < 101 && checkBossPos(9, 0))
        b.x++;
    else if (nb ==2 && (b.x) > 1 && checkBossPos(-1, 0))
        b.x--;
    else if (nb == 3  && (b.y + 7) < 51 && checkBossPos(0, 7))
        b.y++;
    else if ((b.y) > 1 && checkBossPos(0, -1))
        b.y--;
    else
        bossMovement();
    for (int i = 0; i != 7; i++)
        for (int j = 0; j != 10; j++)
            if (map[b.y + i][b.x + j] == '*' || ((b.y+i) == p.y && (b.x+j) == p.x)) {
                p.x = count.x;
                p.y = count.y;
                tmptime = 0;
                for (std::size_t a = 0; a != map.size(); a++)
                    std::replace( map[a].begin(), map[a].end(), '*', ' ');
            }
    score = 0;
}

void qix::tmpplayerMove()
{
    if (tmptime == 20) {
        tmpplayer.xb = count.x;
        tmpplayer.yb = count.y;
        tmpplayer.x = count.x;
        tmpplayer.y = count.y;
        if ((count.x - 1) > 0 && map[count.y][count.x - 1] == '*') {
            tmpplayer.x--;
        } else if ((count.y - 1) > 0 && map[count.y - 1][count.x] == '*') {
            tmpplayer.y--;
        } else if ((count.x + 1) < static_cast<int>(map[0].length()) && map[count.y][count.x + 1] == '*') {
            tmpplayer.x++;
        } else if ((count.y + 1) < static_cast<int>(map.size()) && map[count.y + 1][count.x] == '*') {
            tmpplayer.y++;
        }
    }
    if (map[p.y][p.x] == '#' && map[p.yb][p.xb] != '#') {
        tmptime = 0;
        changeMap();
    }
    if (map[p.y][p.x] == ' ' || map[p.y][p.x] == '*') {
        tmptime++;
        map[p.y][p.x] = '*';
    }
}

// void printPixelArt(char c, std::size_t i, std::size_t j)
// {
//     std::string s = "";
//     s += c;

//     if (c == '1') {
//         attron(COLOR_PAIR(2));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(2));
//     } else if (c == '3') {
//         attron(COLOR_PAIR(4));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(4));
//     } else if (c == '0') {
//         attron(COLOR_PAIR(7));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(7));
//     } else if (c == '2') {
//         attron(COLOR_PAIR(6));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(6));
//     } else if (c == '5') {
//         attron(COLOR_PAIR(3));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(3));
//     } else if (c == '7') {
//         attron(COLOR_PAIR(5));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(5));
//     } else if (c == '4') {
//         attron(COLOR_PAIR(8));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(8));
//     } else if (c == '6') {
//         attron(COLOR_PAIR(9));
//         mvprintw(i, j, s.c_str()); 
//         attroff(COLOR_PAIR(9));
//     }
// }

void qix::incScore()
{
    score++;
}

int qix::getScore() const
{
    return (score);
}

std::vector<std::string> qix::getGameover() const
{
    return (gameover);
}

std::vector<std::string> qix::getMap() const
{
    return (map);
}

std::vector<std::string> qix::getBackground() const
{
    return (background);
}

boss qix::getFirework()
{
    firework.nb++;
    return (firework);
}

boss qix::getBoss() const
{
    return (b);
}

player qix::getPlayer() const
{
    return (p);
}

player qix::getTmpplayer() const
{
    return (tmpplayer);
}

int qix::getTmptime() const
{
    return (tmptime);
}

std::vector<player> qix::getEnnemies() const
{
    return (ennemies);
}

void qix::display(ILib *lib)
{
    std::string s = "";

    if (score == -1) {
        for (std::size_t i = 0; i != gameover.size(); i++)
            for (std::size_t j = 0; j != gameover[i].length(); j++) {
                s = gameover[i][j];
                lib->print(10 + i, 50 + j, s.c_str());
            }
        lib->print(25, 110, "GAME OVER!");
        lib->print(26, 110, "exit : E");
        return;
    }
    if ((score * 100 / 5000) >= 75) {
        for (std::size_t i = 0; i != firework.animeboss[firework.nb].size(); i++)
            lib->print(i , 0, firework.animeboss[firework.nb][i].c_str());
        lib->print(25, 110, "WELL PLAYED!");
        firework.nb++;
        return;
    }
    tmpplayerMove();
    for (std::size_t i = 0; i != map.size(); i++)
        lib->print(i, 0, map[i].c_str());
    lib->print(p.y, p.x, p.c.c_str());
    attron(COLOR_PAIR(1));
    if (tmptime > 20)
        lib->print(tmpplayer.y, tmpplayer.x, "X");
    for (std::size_t i = 0; i != ennemies.size(); i++)
        lib->print(ennemies[i].y, ennemies[i].x, ennemies[i].c.c_str());
    attroff(COLOR_PAIR(1));
    for (std::size_t i = 0; i != b.animeboss[b.nb].size(); i++)
        lib->print(i + b.y, 0 + b.x, b.animeboss[b.nb][i].c_str());
    bossMovement();
    for (std::size_t i = 0; i != background.size(); i++)
        for (std::size_t j = 0; j != background[i].length(); j++)
            if (map[i][j] == 'a') {
                score++;
                s = background[i][j];
                lib->print(i ,j, s.c_str());
            }
    lib->print(25, 110, "CLAIMED :    %%");
    lib->print(26, 110, "exit    :    E");
    lib->print(27, 110, "up      :    Z");
    lib->print(28, 110, "down    :    S");
    lib->print(29, 110, "left    :    Q");
    lib->print(30, 110, "right   :    D");
    lib->print(25, 121, std::to_string(score * 100 / 5000).c_str());
}

void qix::addEnnemies(int x, int y, std::string s)
{
    player e;

    e.c = s;
    e.x = x;
    e.y = y;
    e.xb = x;
    e.yb = y - 1;
    ennemies.push_back(e);
}

void qix::setBackground()
{
    std::ifstream _file("background", std::ios::in);
    std::string buffer;

    while (std::getline(_file, buffer, '\n'))
        background.push_back(buffer);
}

void qix::setFirework()
{
    std::ifstream _file("firework", std::ios::in);
    std::string buffer;
    std::vector<std::string> sprite;
    int nb = 0;

    while (std::getline(_file, buffer, '\n')) {
        sprite.push_back(buffer);
        nb++;
        if (nb % 35 == 0) {
            firework.animeboss.push_back(sprite);
            sprite.clear();
        }
    }
}

void qix::addBoss()
{
    std::ifstream _file("monster", std::ios::in);
    std::string buffer;
    std::vector<std::string> sprite;
    int nb = 0;

    while (std::getline(_file, buffer, '\n')) {
        sprite.push_back(buffer);
        nb++;
        if (nb % 7 == 0) {
            b.animeboss.push_back(sprite);
            sprite.clear();
        }
    }
}

qix::qix()
{
    std::string str = "";

    for (int i = 0; i != 102; i++)
        str += "#";
    map.push_back(str);
    for (int i = 1; i != 51; i++) {
        str = "#";
        for (int j = 1; j != 101; j++)
            str += " ";
        str += "#";
        map.push_back(str);
    }
    str = "";
    for (int i = 0; i != 102; i++)
        str += "#";
    map.push_back(str);
    addEnnemies(0, 25, "X");
    addEnnemies(101, 25, "X");
    setBackground();
    setFirework();
    setGameover();
    addBoss();
    score = 0;
    tmptime = 0;
}