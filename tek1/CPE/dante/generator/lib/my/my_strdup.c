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
    char *ret = NULL;

    if (m_check(ret = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    *ret = '\0';
    my_strcpy(ret, str);
    return (ret);
}