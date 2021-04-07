/*
** EPITECH PROJECT, 2020
** strdowncase
** File description:
** test downcase
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, strup_case_test)
{
    char src[11] = "AZERTYUi";

    my_strlowcase(src);
    cr_assert_str_eq(src, "azertyui");
}
