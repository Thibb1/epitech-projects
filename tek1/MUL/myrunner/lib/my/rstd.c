/*
** EPITECH PROJECT, 2020
** rstd.c
** File description:
** redirects stderr and stdout to criterion
*/

#include "../../include/mytest.h"

void rstd(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
