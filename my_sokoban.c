
/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my sokoban
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "lib/my/my.h"

static int win(char **map, number *nb)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    while (map[i][l] != '\0') {
        while (map[i][j] != '\n' && map[i][j] != '\0') {
            if (map[i][j] == 'O')
                k++;
            j++;
        }
        l = j;
        i++;
        j = 0;
    }
    if (k == 0) {
        l = 2;
        return (l);
    } else
        return (0);
}

static int lose(char **map, number *nb)
{
    int j = 0;
    int l = 0;
    int nb_x = 0;
    int nb_x_del = 0;

    for (int a = 0; map[a][l] != '\0'; a++) {
        while (map[a][j] != '\n' && map[a][j] != '\0') {
            if (map[a][j] == 'X') {
                nb_x++;
                nb_x_del = x_lose(map, a, j, nb_x_del);
            }
            j++;
        }
        l = j;
        j = 0;
    }
    if (nb_x == nb_x_del) {
        return (2);
    } else
        return (0);
}

static void gameloop(char **map, number *nb, int ac, char **av)
{
    int i = 0;
    int j = 0;

    while (nb->key != E) {
        if (i == 2 || j == 2)
            nb->key = 27;
        else {
            clear();
            getmaxyx(stdscr, nb->max_y, nb->max_x);
            nb->middle_y = (nb->max_y / 2);
            nb->middle_x = (nb->max_x / 2);
            print_(map, nb);
            nb->i = 0;
            nb->key = getch();
            move_(map, nb, ac, av);
            i = win(map, nb);
            j = lose(map, nb);
        }
    }
}

static void sokoban(int ac, char **av)
{
    int size = stat_file(av[1]);
    number *nb = malloc(sizeof(number));
    char *buf = malloc(sizeof(char) * (size + 1));
    int fs = open(av[1], O_RDONLY);
    int fd = read(fs, buf, size);
    char **map = my_malloc(buf, nb);

    nb->i = 0;
    nb->x = 0;
    nb->y = 0;
    nb->l = 0;
    copie(buf, map, nb);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    gameloop(map, nb, ac, av);
    endwin();
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
            desc(av);
        else
            sokoban(ac, av);
        return (0);
    } else
        return (84);
}
