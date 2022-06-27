/*
** EPITECH PROJECT, 2020
** tests_str_cpy.c
** File description:
** test str copies
*/

#include "my_test.h"

Test(my_revstr, my_revstr_test)
{
    char src[11] = "HelloWorld";

    cr_assert_str_eq(my_revstr(src), "dlroWolleH");
}

Test(my_strcpy, my_strcpy_test)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq("Hello", dest);
}

Test(my_strncpy, my_strncpy_test)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, my_strncpy_too_big_test)
{
    char dest[6] = {0};

    my_strncpy(dest, "Hel", 6);
    cr_assert_str_eq(dest, "Hel");
}