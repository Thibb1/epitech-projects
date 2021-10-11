/*
** EPITECH PROJECT, 2020
** binary.h
** File description:
** includes for binary binary
*/

#ifndef BINARY
#define BINARY
#include "my.h"
typedef struct settings {
    int li;
    int p;
    int n;
    int width;
    int *nim_arr;
} settings;
int match(int ac, const char *av[]);

int only_num(const char *str);

int get_args(settings *a, int ac, const char *av[]);
int game_init(settings a);

int game_loop(settings a, int *sticks);
int calc_n(settings *a, int *sticks);
void print_sticks(settings *a, int *sticks);

int user_input(settings *a, int *sticks);

int ia_input(settings *a, int *sticks);
#endif