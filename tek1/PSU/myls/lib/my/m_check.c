/*
** EPITECH PROJECT, 2020
** m_check.c
** File description:
** checks malloc return value
*/

#include "../../include/my.h"

void m_check(void *m_ret)
{
    if (!m_ret) {
        write(2, "Error with malloc\n", 18);
        exit (84);
    }
}
