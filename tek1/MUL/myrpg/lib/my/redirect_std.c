/*
** EPITECH PROJECT, 2020
** redirect_std.c
** File description:
** redirects stderr and stdout to criterion
*/

#include "my_test.h"

void redirect_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
