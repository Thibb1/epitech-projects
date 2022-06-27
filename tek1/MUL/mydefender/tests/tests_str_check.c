/*
** EPITECH PROJECT, 2020
** tests_str_check.c
** File description:
** test str checker
*/

#include "my_test.h"

Test(my_strncat, str_ncat_test)
{
    char src[30] = "ab";
    my_strncat(src, "acb", 2);
    cr_assert_str_eq("abac", src);
}

Test(my_swap, swapper_test)
{
    int a = 2;
    int b = 3;
    my_swap(&a, &b);
    cr_assert_eq(a - b, 1);
}
