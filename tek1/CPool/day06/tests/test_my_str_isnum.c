/*
** EPITECH PROJECT, 2020
** str nb test
** File description:
** test str nb
*/

#include <criterion/criterion.h>

#include <string.h>

int my_str_isnum(char const *str);

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
