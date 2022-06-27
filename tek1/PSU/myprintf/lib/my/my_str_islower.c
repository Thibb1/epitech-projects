/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** returns True if str if lower
*/

#include "../../include/my.h"

int my_small(char c)
{
    if (!(c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_small(str[i]))
            return (0);
    return (1);
}
