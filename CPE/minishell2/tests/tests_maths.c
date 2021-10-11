/*
** EPITECH PROJECT, 2021
** tests_maths.c
** File description:
** tests on maths functions
*/

#include "my_test.h"

Test(my_pow, my_pow_test)
{
    int x = my_pow(10, 2);

    cr_assert_eq(100, x);
}

Test(my_sqrt, my_sqrt_test)
{
    int x = my_sqrt(49);

    cr_assert_eq(x, 7);
}

Test(my_pow, my_pow_neg_test)
{
    int x = my_pow(10, -1);

    cr_assert_eq(x, 1);
}

Test(my_sqrt, my_sqrt_neg_test)
{
    int x = my_sqrt(-49);

    cr_assert_eq(x, -1);
}