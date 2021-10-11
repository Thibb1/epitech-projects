/*
** EPITECH PROJECT, 2020
** put_isprintable.c
** File description:
** put non-ascii printable char
*/

#include "../../include/my.h"

int my_putisprintable(char c)
{
    int count = my_putchar(92);
    count += my_putchar('0');
    count += my_putchar((c / 10) % 10 + '0');
    count += my_putchar(c % 10 + '0');
    return (count);
}
