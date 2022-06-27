/*
** EPITECH PROJECT, 2020
** my_putnstr.c
** File description:
** print nb char of str
*/

#include "my_printf.h"

int my_putnstr(int fd, char const *str, int nb)
{
    int i = 0;

    for (; str[i] && i < nb;)
        i += my_putchar(fd, str[i]);
    return (i);
}
