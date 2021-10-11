/*
** EPITECH PROJECT, 2020
** tests_nbr_utils.c
** File description:
** test the nbr utils
*/

#include "../include/mytest.h"

Test(my_putnbrbase, putnbr_hex, .init = rstd)
{
    char base[17] = "0123456789ABCDEF";
    int nbr = 24567;
    my_putnbrbase(nbr, base);
    cr_assert_stdout_eq_str("5FF7");
}

Test(my_putnbrbase, putnbr_base_two, .init = rstd)
{
    char base[] = "01";
    int nbr = 123;
    my_putnbrbase(nbr, base);
    cr_assert_stdout_eq_str("1111011");
}

Test(my_putnbrbase, putnbr_base_zero, .init = rstd)
{
    char base[] = "01";
    int nbr = 0;
    my_putnbrbase(nbr, base);
    cr_assert_stdout_eq_str("0");
}

Test(my_is_numone, num_one_test)
{
    int a = my_is_numone('1') + my_is_numone('a');
    cr_assert_eq(1, a);
}
