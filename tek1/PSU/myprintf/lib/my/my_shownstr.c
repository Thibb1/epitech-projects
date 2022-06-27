/*
** EPITECH PROJECT, 2020
** my_shownstr.c
** File description:
** text and non-ascii in dec until n
*/

#include "../../include/my.h"

int my_putnisprintable(char c, int nb)
{
    int count = my_putchar(92);
    count += my_putchar('0');
    if (count < nb)
        count += my_putchar((c / 10) % 10 + '0');
    if (count < nb)
        count += my_putchar(c % 10 + '0');
    return (count);
}

int my_shownstr(char const *str, int nb)
{
    int count = 0;
    int i = 0;

    for (; str[i] && count < nb; i++) {
        if (my_is_printable(str[i]))
            count += my_putnisprintable(str[i], nb - count);
        else
            count += my_putchar(str[i]);
    }
    return (count);
}
