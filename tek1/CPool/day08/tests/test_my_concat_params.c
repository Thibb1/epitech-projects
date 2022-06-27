/*
** EPITECH PROJECT, 2020
** test_my_strdup
** File description:
** test my_strdup
*/

#include <criterion/criterion.h>

#include "../include/my.h"

char *concat_params(int argc, char **argv);

Test(concat_params, two_arg_test)
{
    char *str[] = {"Hey", "Test"};
    cr_assert_eq(my_putstr(concat_params(2, str)), 0);
}
