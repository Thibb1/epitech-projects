/*
** EPITECH PROJECT, 2020
** my_ferror.c
** File description:
** return error and prints an error
*/

#include "my.h"

int my_ferror(const char *error)
{
    my_dprintf(STDERR_FILENO, "%s\n", error);
    return (FAILURE);
}

int m_check(void *m_ret)
{
    return (m_ret == NULL ? my_ferror("Error with malloc") : SUCCESS);
}