/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** copy src in dest
*/

#include "my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *ret = malloc(sizeof(char) * (len + 1));

    if (ret == NULL)
        return (NULL);
    ret = my_strcpy(ret, str);
    return (ret);
}