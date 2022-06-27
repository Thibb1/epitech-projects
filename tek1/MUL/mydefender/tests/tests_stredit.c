/*
** EPITECH PROJECT, 2020
** tests_stredit.c
** File description:
** test str manipulation
*/

#include "my_test.h"

Test(my_revstr, rev_string)
{
    char src[11] = "HelloWorld";
    cr_assert_str_eq(my_revstr(src), "dlroWolleH");
}

Test(my_strcapitalize, str_capitalize_test)
{
    char src[30] = "bonJour-EspECe de 12toto";

    my_strcapitalize(src);
    cr_assert_str_eq(src, "Bonjour-Espece De 12toto");
}

Test(my_strlowcase, strup_case_test)
{
    char src[11] = "AZERTYUi";

    my_strlowcase(src);
    cr_assert_str_eq(src, "azertyui");
}
