/*
** EPITECH PROJECT, 2020
** my_is_alpha_num.c
** File description:
** returns True if c alphanum
*/

#include "../../include/my.h"

int my_is_alpha_num(char c)
{
    if (!(my_is_alpha_one(c)) || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}
