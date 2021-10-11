/*
** EPITECH PROJECT, 2020
** tests_my_printf.c
** File description:
** tests_on_printf.c
*/

#include "../include/mytest.h"

Test(my_printf, flag_nbr, .init = rstd)
{
    my_printf("% d%+3d%3i%+-4d\n", 42, 42, 42, -42);
    cr_assert_stdout_eq_str(" 42+42 42-42 \n");
}

Test(my_printf, flag_modulo_false_c, .init = rstd)
{
    my_printf("%%%#+-10.18w%2c%-2c", 42, 42);
    cr_assert_stdout_eq_str("%%#+-10.18w ** ");
}

Test(my_printf, flag_base, .init = rstd)
{
    my_printf("%#o%u%#x%#X", 012345, 3000000000, 0x12345, 0x12345);
    cr_assert_stdout_eq_str("01234530000000000x123450X12345");
}

Test(my_printf, flag_base2, .init = rstd)
{
    char *st = "kiw";
    char str[] = {'K', 'i', 18, 'w', 0};
    int r = my_printf("%4.2s%-10S%b%p", st, str, 1564545, st);
    int b = my_printf("%s%.2S", st, str);
    r += b;
    cr_assert_eq(r, 51);
}
