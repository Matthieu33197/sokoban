/*
** EPITECH PROJECT, 2019
** my
** File description:
** all my
*/

#ifndef __MY_H__
#define __MY_H__
#define L KEY_LEFT
#define R KEY_RIGHT
#define U KEY_UP
#define D KEY_DOWN
#define S 32
#define E 27

typedef struct nb_struct
{
    int max_y;
    int max_x;
    int middle_y;
    int middle_x;
    int i;
    int x;
    int y;
    int n;
    int m;
    int key;
    int l;
    int line;
    int x_bis;
    int y_bis;
} number;

void copie(char *buf, char **map, number *nb);
char **my_malloc(char *buf, number *nb);
void print_(char **map, number *nb);
char **mem_alloc_2d_array(int nb_row, int nb_cols);
unsigned int stat_file(char const *filepath);
void desc(char **av);
int x_lose(char **map, int a, int j, int nb_x_del);
void switch5(char **map, number *nb, int ac, char **av);
void switch3(char **map, number *nb, int ac, char **av);
void switch4(char **map, number *nb, int ac, char **av);
void move_(char **map, number *nb, int ac, char **av);
void switch2(char **map, number *nb, int ac, char **av);
#endif
