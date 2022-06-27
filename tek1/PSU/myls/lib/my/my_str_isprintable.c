/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** return True if str is pritable
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_printable(str[i]))
            return (0);
    return (1);
}
