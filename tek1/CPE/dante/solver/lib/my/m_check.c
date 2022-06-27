/*
** EPITECH PROJECT, 2020
** m_check.c
** File description:
** checks malloc return value
*/

#include "my.h"

int m_check(void *m_ret)
{
    if (m_ret == NULL)
        return (my_ferror("./solver: malloc error"));
    return (SUCCESS);
}
