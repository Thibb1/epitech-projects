/*
** EPITECH PROJECT, 2020
** tests_nbr_func.c
** File description:
** test the nbr func
*/

#include "my_test.h"

Test(my_getnbr, get_nbr)
{
    int a = my_getnbr("214700000000");
    a = my_getnbr("-10");
    a = my_getnbr("10");
    cr_assert_eq(a, 10);
}