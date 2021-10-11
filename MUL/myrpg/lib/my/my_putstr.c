/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print string in fd buffer
*/

#include "my_printf.h"

int my_putstr(int fd, char const *str)
{
    int i = my_strlen(str);

    write(fd, str, i);
    return (i);
}

int my_putnstr(int fd, char const *str, int nb)
{
    int i = 0;

    for (; str[i] && i < nb;)
        i += my_putchar(fd, str[i]);
    return (i);
}