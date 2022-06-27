/*
** EPITECH PROJECT, 2020
** ferror.c
** File description:
** return error and prints an error
*/

#include "my.h"

int my_ferror(const char *error)
{
    my_printf("%s\n", error);
    return (FAILURE);
}
