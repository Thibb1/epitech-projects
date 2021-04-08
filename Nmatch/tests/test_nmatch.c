/*
** EPITECH PROJECT, 2020
** nmatch tester
** File description:
** nmatch tester
*/

#include <criterion/criterion.h>

int nmatch(char const *s1, char const *s2);

Test(nmatch, test_nmatch_star_at_end)
{
    const char s1[] = "hello_world";
    const char s2[] = "hel**";

    cr_assert_eq(nmatch(s1, s2) ? 1 : 0, 1);
}

Test(match, test_no_nmatch)
{
    const char s1[] = "hello_i_am_z";
    const char s2[] = "*zz*";

    cr_assert_eq(nmatch(s1, s2), 0);
}

Test(match, test_nstar_at_start)
{
    const char s1[] = "hello_you";
    const char s2[] = "**hello";

    cr_assert_eq(nmatch(s1, s2), 0);
}

Test(match, only_nstar)
{
    const char s1[] = "should_match";
    const char s2[] = "**";


    cr_assert_eq(nmatch(s1, s2) ? 1 : 0, 1);
}
