/*
** EPITECH PROJECT, 2020
** test my_strstr
** File description:
** test revstr
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, find_strstr)
{
    char src[11] = "HelloWorld";
    char scra[11] = "HelloWorld";

    cr_assert_str_eq(my_strstr(src, "World"), strstr(scra, "World"));
}

Test(my_strstr, find_strstr_short_word)
{
    char src[11] = "HelloWorld";
    char scra[11] = "HelloWorld";

    cr_assert_str_eq(my_strstr(src, "W"), strstr(scra, "W"));
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

    cr_assert_str_eq(my_strstr(src, "lo"), strstr(scra, "lo"));
}
