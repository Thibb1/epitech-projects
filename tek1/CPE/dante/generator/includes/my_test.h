/*
** EPITECH PROJECT, 2020
** my_test.h
** File description:
** includes for criterion tests
*/

#ifndef MY_TEST
#define MY_TEST
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "my_printf.h"

/// @brief Redirect output to criterion to make unit tests
void redirect_std(void);
#endif