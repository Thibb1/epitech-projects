/*
** EPITECH PROJECT, 2020
** check_tower.c
** File description:
** check if tower in range
*/

#include "defender.h"

void nb_to_str(char str[1048], int nb)
{
    int i = 0;

    int nbp = M_ABS(nb);
    for (; str[i++];);
    i--;
    if (nb == 0)
        str[i++] = '0';
    for (; nbp >= 1; nbp /= 10, i++)
        str[i] = nbp % 10 + '0';
    if (nb < 0)
        str[i++] = '-';
    str[i] = 0;
    my_revstr(str);
}
