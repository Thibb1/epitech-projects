/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** returns length of str
*/

#include "my.h"

int my_strlen(char const *str)
{
    int length = 0;

    for (; str[length]; length++);
    return (length);
}