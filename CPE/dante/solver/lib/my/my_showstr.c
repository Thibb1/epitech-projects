/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** text and non-ascii in dec
*/

#include "my_printf.h"

int my_showstr(int fd, char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (my_is_printable(str[i]))
            count += my_putisprintable(fd, str[i]);
        else
            count += my_putchar(fd, str[i]);
    }
    return (count);
}
