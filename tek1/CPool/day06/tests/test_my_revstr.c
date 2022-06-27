/*
** EPITECH PROJECT, 2020
** test revstr
** File description:
** test revstr
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_revstr(char *str);

Test(my_revstr, rev_string)
{
    char src[11] = "HelloWorld";
    cr_assert_str_eq(my_revstr(src), "dlroWolleH");
}
