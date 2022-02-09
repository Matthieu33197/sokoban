/*
** EPITECH PROJECT, 2019
** funct_3
** File description:
** funct 3
*/

#include <ncurses.h>
#include "my.h"

void move_(char **map, number *nb, int ac, char **av)
{
    switch (nb->key) {
    case S:
        main(ac, av);
        break;
    default:
        switch2(map, nb, ac, av);
    }
}
