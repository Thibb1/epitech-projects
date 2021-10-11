/*
** EPITECH PROJECT, 2020
** my_putnbr.c
** File description:
** display nb
*/

#include "../../include/my.h"

int my_putnbr(int nb)
{
    int count = 0;
    long lnb = ABS(nb);
    char rnb[12];
    for (; lnb > 0; lnb /= 10)
        rnb[count++] = lnb % 10 + '0';
    if (nb == 0)
        rnb[count++] = '0';
    rnb[count] = 0;
    for (int i = count - 1; i >= 0; i--)
        my_putchar(rnb[i]);
    return (count);
}
