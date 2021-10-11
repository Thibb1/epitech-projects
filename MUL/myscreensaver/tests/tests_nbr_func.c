/*
** EPITECH PROJECT, 2020
** tests_nbr_func.c
** File description:
** test the nbr func
*/

#include "../include/mytest.h"

Test(my_compute_power_rec, test_power)
{
    int a = my_compute_power_rec(10, -1);
    a = my_compute_power_rec(10, 2);
    cr_assert_eq(a, 100);
}

Test(my_compute_square_root, test_square)
{
    int a = my_compute_square_root(10);
    a = my_compute_square_root(0);
    a = my_compute_square_root(4);
    cr_assert_eq(a, 2);
}

Test(my_find_prime_sup, test_prime)
{
    int a = my_find_prime_sup(0);
    a = my_find_prime_sup(8);
    cr_assert_eq(a, 11);
}

Test(my_is_prime, test_prime_two)
{
    int a = my_is_prime(2);
    a = my_is_prime(10);
    a = my_is_prime(11);
    cr_assert_eq(a, 1);
}

Test(my_getnbr, get_nbr)
{
    int a = my_getnbr("214700000000");
    a = my_getnbr("-10");
    a = my_getnbr("10");
    cr_assert_eq(a, 10);
}
