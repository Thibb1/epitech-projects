/*
** EPITECH PROJECT, 2020
** tests_str_check.c
** File description:
** test str checker
*/

#include "../include/mytest.h"

Test(my_str_isnum, str_isnum_test)
{
    char src[30] = "1b1onjour E de toto";
    int alpha = my_str_isnum(src);

    cr_assert_eq(alpha, 0);
}

Test(my_str_isalpha, str_isnum_test_true)
{
    char src[2] = "15";
    int alpha = my_str_isnum(src);

    cr_assert_eq(alpha, 1);
}

Test(my_str_isalpha, str_isnum_test_empty_string)
{
    char src[30] = "";
    int alpha = my_str_isnum(src);

    cr_assert_eq(alpha, 1);
}

Test(my_strncat, str_ncat_test)
{
    char src[30] = "ab";
    my_strncat(src, "acb", 2);
    cr_assert_str_eq("abac", src);
}

Test(my_swap, swaper_test)
{
    int a = 2;
    int b = 3;
    my_swap(&a, &b);
    cr_assert_eq(a - b, 1);
}
