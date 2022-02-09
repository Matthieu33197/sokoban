/*
** EPITECH PROJECT, 2019
** func_1
** File description:
** func 1
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char **my_malloc(char *buf, number *nb)
{
    int col = 0;

    nb->line = 0;
    for (col = 0; buf[col] != '\0';col++) {
        if (buf[col] == '\n')
            nb->line++;
    }
    nb->line++;
    col = (col - nb->line) / nb->line;
    return (mem_alloc_2d_array(nb->line, col));
}

void copie(char *buf, char **map, number *nb)
{
    int j = 0;
    int n = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        while (buf[i] != '\n' && buf[i] != '\0') {
            if (buf[i] == 'P') {
                buf[i] = ' ';
                nb->x = n;
                nb->y = j;
                nb->x_bis = n;
                nb->y_bis = j;
            }
            map[j][n] = buf[i];
            n++;
            i++;
        }
        map[j][n] = buf[i];
        j++;
        n = 0;
    }
}

void print_(char **map, number *nb)
{
    while (map[nb->i]) {
        mvprintw(nb->middle_y, nb->middle_x, map[nb->i]);
        nb->i++;
        nb->middle_y++;
    }
    if (nb->l != 1) {
        nb->y += (nb->max_y / 2);
        nb->x += (nb->max_x / 2);
        nb->l++;
    }
    mvprintw(nb->y, nb->x, "P");
}

unsigned int stat_file(char const *filepath)
{
    struct stat sb;

    stat(filepath, &sb);
    return (sb.st_size);
}

void desc(char **av)
{
    int fs = open("des", O_RDONLY);
    int size = stat_file("des");
    char *buf = malloc(sizeof(char) * (size + 1));
    int fd = read(fs, buf, size);

    write(1, buf, size);
}
