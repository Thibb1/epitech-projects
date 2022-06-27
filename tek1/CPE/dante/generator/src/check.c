/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** check inputs
*/

#include "generator.h"

int positive_int(const char *str)
{
    for (;*str;)
        if (*str < '0' || *str++ > '9')
            return (0);
    return (1);
}