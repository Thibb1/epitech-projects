/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** concatenates n of src in dest
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, const int nb)
{
    int i = 0;
    int j = my_strlen(dest);
    for (; src[i] && nb > i; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}
