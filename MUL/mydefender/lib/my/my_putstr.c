/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print str
*/

#include "my.h"

int my_putstr(int fd, char const *str)
{
    int i = my_strlen(str);

    write(fd, str, i);
    return (i);
}
