/*
** EPITECH PROJECT, 2020
** binary.h
** File description:
** includes for binary binary
*/
#include "my.h"

#ifndef BINARY
#define BINARY
#define RAND(x, y) ((y) + rand() % ((x) - (y)))
#define RAND_INT(x, y) ((x) > (y) ? RAND((x) + 1, y) : RAND((y) + 1, x))
int generator(int ac, char **av);
int generator_perfect(int x, int y);
int generator_imperfect(int x, int y);
int positive_int(const char *str);
char **init_map(int x, int y);
void show_free_map(int x, int y, char **map);
void carve_wall(char **map, int i, int j, int coords[2]);
void show_free_map1(int x, int y, char **map);
void add_cluster(int x, int y, char **map);
#endif