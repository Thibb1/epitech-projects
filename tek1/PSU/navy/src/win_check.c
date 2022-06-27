/*
** EPITECH PROJECT, 2020
** win_check.c
** File description:
** navy game
*/

#include "../include/my.h"
#include "../include/navy.h"

void print_win(int win)
{
    if (win == 1) {
        my_printf("I won\n");
    } else
        my_printf("Enemy won\n");
}

int check_win(char map[2][8][8])
{
    int hit = 0;
    int left = 14;

    for (int i = 0; i < 8; i++)
        for (int b = 0; b < 8; b++)
            left -= map[0][i][b] == 'x';
    if (!left)
        return (-1);
    for (int i = 0; i < 8; i++)
        for (int b = 0; b < 8; b++)
            hit += map[1][i][b] == 'x';
    return (hit == 14 ? 1 : 0);
}