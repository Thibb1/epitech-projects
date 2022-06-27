/*
** EPITECH PROJECT, 2020
** put_isprintable.c
** File description:
** put non-ascii printable char
*/

#include "my_printf.h"

int my_putisprintable(int fd, char c)
{
    int count = my_putchar(fd, 92);

    count += my_putchar(fd, '0');
    count += my_putchar(fd, (c / 10) % 10 + '0');
    count += my_putchar(fd, c % 10 + '0');
    return (count);
}
