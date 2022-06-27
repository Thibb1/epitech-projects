/*
** EPITECH PROJECT, 2020
** tests_str_utils.c
** File description:
** tests the str utils
*/

#include "../include/mytest.h"

Test(my_showstr, showstr_test_big_text, .init = rstd)
{
    char std[] = {'K', 'i', 12, 'w', 0};
    my_showstr(std);
    cr_assert_stdout_eq_str("Ki\\012w");
}

Test(my_strcmp, comp_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abcd";
    int a = my_strcmp(str1, str2);
    cr_assert(a);
}

Test(my_strcmp, comp_same_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abzd";
    int a = my_strcmp(str1, str2);
    cr_assert_eq(a, 0);
}

Test(my_str_isprintable, str_isprintable_test)
{
    char src[30] = "bonjour Espèçe de toto";
    int printable = my_str_isprintable(src);

    cr_assert_eq(printable, 0);
}

Test(my_str_isprintable, str_isprintable_test_true)
{
    char src[30] = "BONJOUR";
    int printable = my_str_isprintable(src);

    cr_assert_eq(printable, 1);
}
