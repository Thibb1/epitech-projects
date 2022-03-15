/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concatenates characters of the str in dest
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);

    for (; src[i]; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}

char *my_strncat(char *dest, char const *src, const int nb)
{
    int i = 0;
    int j = my_strlen(dest);

    for (; src[i] && nb > i; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}
