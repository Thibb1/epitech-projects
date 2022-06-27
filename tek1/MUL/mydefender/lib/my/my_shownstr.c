/*
** EPITECH PROJECT, 2020
** my_shownstr.c
** File description:
** text and non-ascii in dec until n
*/

#include "my_printf.h"

int my_putnisprintable(int fd, char c, int nb)
{
    int count = my_putchar(fd, 92);

    count += my_putchar(fd, '0');
    if (count < nb)
        count += my_putchar(fd, (c / 10) % 10 + '0');
    if (count < nb)
        count += my_putchar(fd, c % 10 + '0');
    return (count);
}

int my_shownstr(int fd, char const *str, int nb)
{
    int count = 0;
    int i = 0;

    for (; str[i] && count < nb; i++) {
        if (my_is_printable(str[i]))
            count += my_putnisprintable(fd, str[i], nb - count);
        else
            count += my_putchar(fd, str[i]);
    }
    return (count);
}
