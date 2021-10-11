/*
** EPITECH PROJECT, 2020
** ferror.c
** File description:
** exit and prints an error
*/

#include "../../include/my.h"
#include "../../include/myprintf.h"

int my_ferror(const char *error)
{
    my_printf("%s\n", error);
    return (84);
}
