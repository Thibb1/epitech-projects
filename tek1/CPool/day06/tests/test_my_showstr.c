/*
** EPITECH PROJECT, 2020
** test showstr
** File description:
** tests the showstr func
*/

#include <criterion/criterion.h>

int my_showstr(char const *str);

Test(my_showstr, showstr_test_big_text)
{
    int a = my_showstr("Coucou la mif \n whatsupp ?!");

    cr_assert_eq(a, 0);
}
