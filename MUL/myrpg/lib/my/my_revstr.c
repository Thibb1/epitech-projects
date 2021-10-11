/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reverses a string in itself
*/

#include "my.h"

char *my_revstr(char *str)
{
    char c;
    int x = 0;
    int n = my_strlen(str);

    while (2 * x < n) {
        c = *(str + x);
        *(str + x) = *(str + n - x - 1);
        *(str + n - x++ - 1) = c;
    }
    return (str);
}