/*
** EPITECH PROJECT, 2020
** test_de_op
** File description:
** tester de op
*/

#include <criterion/criterion.h>
#include "../include/my.h"

double do_op(char *argv[]);

int do_test(char *argv[])
{
    double a = do_op(argv);

    if (a == -12.5 || a == -12.3)
        return (84);
    my_put_nbr((int)a);
    return (0);
}

Test(do_test, test_adivb)
{
    char *str[] = {"a", "---13", "/", "23"};
    cr_assert_eq(do_test(str), 0);
}

Test(do_test, test_amodb)
{
    char *str[] = {"a", "---13", "%", "10"};
    cr_assert_eq(do_test(str), 0);
}

Test(do_test, test_divzero)
{
    char *str[] = {"a", "20", "/", "0"};
    cr_assert_eq(do_test(str), 84);
}

Test(do_test, test_modzero)
{
    char *str[] = {"a", "20", "%", "0"};
    cr_assert_eq(do_test(str), 84);
}
