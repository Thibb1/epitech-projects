/*
** EPITECH PROJECT, 2020
** tests_str_cmp.c
** File description:
** tests the str cmp
*/

#include "my_test.h"

Test(my_strcmp, my_strcmp_s1_to_s2_test)
{
    char str1[] = "hello";
    char str2[] = "hell no";
    int a = my_strcmp(str1, str2);

    cr_assert(a);
}

Test(my_strcmp, my_strcmp_same_s1_to_s2_test)
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    int a = my_strcmp(str1, str2);

    cr_assert_eq(a, 0);
}

Test(my_strdup, my_strdup_test, .init = redirect_std)
{
    char *test = NULL;

    test = my_strdup("Hello");
    my_printf("%s", test);
    free(test);
    cr_assert_stdout_eq_str("Hello");
}