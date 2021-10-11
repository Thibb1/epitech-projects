/*
** EPITECH PROJECT, 2020
** my_putnstr.c
** File description:
** print n str
*/

#include "../../include/my.h"

int my_putnstr(char const *str, int nb)
{
    int i = 0;
    for (; str[i] && i < nb;)
        i += my_putchar(str[i]);
    return (i);
}
