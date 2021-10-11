/*
** EPITECH PROJECT, 2020
** tests_atoi_atof.c
** File description:
** test my_atoi and my_atof funct
*/

#include "my_test.h"

Test(my_atoi, my_atoi_test)
{
    int a = my_atoi("+2147000000");

    cr_assert_eq(a, 2147000000);
}

Test(my_atof, my_atof_test)
{
    double a = my_atof("-12.34");

    cr_assert_eq(a, -12.34);
}

Test(my_itoa, my_itoa_test, .init = redirect_std)
{
    char *str = my_itoa(-33);

    my_printf("%d", my_ilen(1));
    my_printf("%d", my_ilen(10));
    my_printf("%d", my_ilen(100));
    my_printf("%d", my_ilen(1000));
    my_printf("%d", my_ilen(10000));
    my_printf("%d", my_ilen(100000));
    my_printf("%d", my_ilen(1000000));
    my_printf("%d", my_ilen(10000000));
    my_printf("%d", my_ilen(100000000));
    my_printf("%d", my_ilen(1000000000));
    my_printf("%s", str);
    free(str);
    cr_assert_stdout_eq_str("12345678910-33");
}