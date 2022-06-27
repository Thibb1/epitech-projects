/*
** EPITECH PROJECT, 2020
** tests_my_printf.c
** File description:
** tests_on_printf.c
*/

#include "my_test.h"

Test(my_printf, flag_nbr, .init = redirect_std)
{
    my_printf("% d%+3d%+-4d\n", 42, 42, -42);
    cr_assert_stdout_eq_str(" 42+42-42 \n");
}

Test(my_printf, flag_modulo_false_c, .init = redirect_std)
{
    my_printf("%%%#+-10.18w%2c%-2c", 42, 42);
    cr_assert_stdout_eq_str("%%#+-10.18w ** ");
}

Test(my_printf, flag_base2, .init = redirect_std)
{
    int r = my_printf("Hello %.5s", "world!");

    cr_assert_eq(r, 11);
}

Test(m_check, m_check_test, .init = redirect_std)
{
    char *str = NULL;

    m_check(str);
    cr_assert_stderr_eq_str("Error with malloc\n");
}