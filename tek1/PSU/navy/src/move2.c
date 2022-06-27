/*
** EPITECH PROJECT, 2020
** move2.c
** File description:
** navy game
*/

#include "../include/my.h"
#include "../include/navy.h"

int check_pos(char c)
{
    if (c != 'x' && (c < '2' || c > '5'))
        return (0);
    return (1);
}

int check_hit(char map[2][8][8], char move[4], int x[2])
{
    if (check_pos(map[0][x[0]][x[1]])) {
        map[0][x[0]][x[1]] = 'x';
        my_printf("%s: hit\n\n", move);
        return (1);
    } else {
        map[0][x[0]][x[1]] = 'o';
        my_printf("%s: missed\n\n", move);
    }
    return (0);
}

int apply_move(char map[2][8][8], char move[4], int mode)
{
    int x[2] = {move[0] - 'A', move[1] - '1'};
    if (mode == 2) {
        return (check_hit(map, move, x));
    } else if (mode == 1) {
        map[1][x[0]][x[1]] = 'x';
        my_printf("%s: hit\n\n", move);
    } else {
        map[1][x[0]][x[1]] = 'o';
        my_printf("%s: missed\n\n", move);
    }
    return (0);
}