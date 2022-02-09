/*
** EPITECH PROJECT, 2019
** funct_2
** File description:
** funct 2
*/

#include <ncurses.h>
#include "my.h"

int x_lose(char **map, int a, int j, int nb_x_del)
{
    if (map[a][j + 1] == '#' && map[a - 1][j] == '#')
        nb_x_del++;
    else if (map[a][j - 1] == '#' && map[a - 1][j] == '#')
        nb_x_del++;
    else if (map[a][j + 1] == '#' && map[a + 1][j] == '#')
        nb_x_del++;
    else if (map[a][j - 1] == '#' && map[a + 1][j] == '#')
        nb_x_del++;
    return (nb_x_del);
}

void switch5(char **map, number *nb, int ac, char **av)
{
    switch (nb->key) {
    case L:
        if (map[nb->y_bis][nb->x_bis - 1] != '#' &&
            map[nb->y_bis][nb->x_bis - 1] != 'X') {
            nb->x_bis--;
            nb->x--;
        } else if (map[nb->y_bis][nb->x_bis - 1] == 'X' &&
                   (map[nb->y_bis][nb->x_bis - 2] == ' ' ||
                    map[nb->y_bis][nb->x_bis - 2] == 'O')) {
            map[nb->y_bis][nb->x_bis - 1] = ' ';
            nb->x_bis--;
            nb->x--;
            map[nb->y_bis][nb->x_bis - 1] = 'X';
        }
        break;
    }
}

void switch4(char **map, number *nb, int ac, char **av)
{
    switch (nb->key) {
    case D:
        if (map[nb->y_bis + 1][nb->x_bis] != '#' &&
            map[nb->y_bis + 1][nb->x_bis] != 'X') {
            nb->y_bis++;
            nb->y++;
        } else if (map[nb->y_bis + 1][nb->x_bis] == 'X' &&
                   (map[nb->y_bis + 2][nb->x_bis] == ' ' ||
                    map[nb->y_bis + 2][nb->x_bis] == 'O')) {
            map[nb->y_bis + 1][nb->x_bis] = ' ';
            nb->y_bis++;
            nb->y++;
            map[nb->y_bis + 1][nb->x_bis] = 'X';
        }
        break;
    default:
        switch5(map, nb, ac, av);
    }
}

void switch3(char **map, number *nb, int ac, char **av)
{
    switch (nb->key) {
    case U:
        if (map[nb->y_bis - 1][nb->x_bis] != '#' &&
            map[nb->y_bis - 1][nb->x_bis] != 'X') {
            nb->y_bis--;
            nb->y--;
        } else if (map[nb->y_bis - 1][nb->x_bis] == 'X' &&
                   (map[nb->y_bis - 2][nb->x_bis] == ' ' ||
                    map[nb->y_bis - 2][nb->x_bis] == 'O')) {
            map[nb->y_bis - 1][nb->x_bis] = ' ';
            nb->y_bis--;
            nb->y--;
            map[nb->y_bis - 1][nb->x_bis] = 'X';
        }
        break;
    default:
        switch4(map, nb, ac, av);
        break;
    }
}

void switch2(char **map, number *nb, int ac, char **av)
{
    switch (nb->key) {
    case R:
        if (map[nb->y_bis][nb->x_bis + 1] != '#' &&
            map[nb->y_bis][nb->x_bis + 1] != 'X') {
            nb->x_bis++;
            nb->x++;
        } else if (map[nb->y_bis][nb->x_bis + 1] == 'X' &&
                   (map[nb->y_bis][nb->x_bis + 2] == ' ' ||
                    map[nb->y_bis][nb->x_bis + 2] == 'O')) {
            map[nb->y_bis][nb->x_bis + 1] = ' ';
            nb->x_bis++;
            nb->x++;
            map[nb->y_bis][nb->x_bis + 1] = 'X';
        }
        break;
    default:
        switch3(map, nb, ac, av);
        break;
    }
}
