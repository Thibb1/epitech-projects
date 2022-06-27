/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print str
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    i = my_strlen(str);
    write(1, str, i);
    return (i);
}
