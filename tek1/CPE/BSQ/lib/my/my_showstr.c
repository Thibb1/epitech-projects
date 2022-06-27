/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** text and non-ascii in dec
*/

#include "../../include/my.h"

int my_showstr(char const *str)
{
    int count = 0;
    int i = 0;

    for (; str[i]; i++) {
        if (my_is_printable(str[i]))
            count += my_putisprintable(str[i]);
        else
            count += my_putchar(str[i]);
    }
    return (count);
}
