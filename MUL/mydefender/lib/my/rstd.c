/*
** EPITECH PROJECT, 2020
** rstd.c
** File description:
** redirects stderr and stdout to criterion
*/

#include "my_test.h"

void rstd(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
