/*
** EPITECH PROJECT, 2020
** my_str_isupper.c
** File description:
** return True if str not only upper
*/

#include "../../include/my.h"

int my_big(char c)
{
    if (!(c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_big(str[i]))
            return (0);
    return (1);
}
