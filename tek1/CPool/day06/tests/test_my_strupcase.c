/*
** EPITECH PROJECT, 2020
** strupcase tester
** File description:
** tests strupcase
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_strupcase(char *str);

Test(my_strupcase, strup_case_test)
{
    char src[11] = "azertyuI";

    my_strupcase(src);
    cr_assert_str_eq(src, "AZERTYUI");
}
