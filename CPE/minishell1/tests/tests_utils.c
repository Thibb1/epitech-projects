/*
** EPITECH PROJECT, 2020
** tests_utils.c
** File description:
** test utils
*/

#include "my_test.h"

Test(my_strcpy, copy_string_into_dest)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq("Hello", dest);
}
