/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** malloc for str
*/

#include <stdlib.h>

#include "include/my.h"

char *my_strdup(char const *src)
{
    int s_src = my_strlen(src);
    char *s_ret = malloc(sizeof(char) * s_src);

    my_strcpy(s_ret, src);
    return (s_ret);
}
