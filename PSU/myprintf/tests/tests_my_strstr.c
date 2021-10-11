/*
** EPITECH PROJECT, 2020
** test my_strstr
** File description:
** test revstr
*/

#include "../include/mytest.h"

Test(my_strstr, find_strstr)
{
    char src[11] = "HelloWorld";
    char scra[11] = "HelloWorld";

    cr_assert_str_eq(my_strstr(src, "World"), "World");
}

Test(my_strstr, find_strstr_short_word)
{
    char src[11] = "HelloWorld";
    char scra[11] = "HelloWorld";

    cr_assert_str_eq(my_strstr(src, "W"), "World");
}

Test(my_strstr, find_strstr_no_match)
{
    char src[11] = "HelloWorld";

    cr_assert_null(my_strstr(src, "duh"));
}

Test(my_strstr, find_strstr_last_letters)
{
    char src[11] = "Hello";
    char scra[11] = "Hello";

    cr_assert_str_eq(my_strstr(src, "lo"), "lo");
}

Test(my_strupcase, strup_case_test)
{
    char src[11] = "azertyuI";

    my_strupcase(src);
    cr_assert_str_eq(src, "AZERTYUI");
}
