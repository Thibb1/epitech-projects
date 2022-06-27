/*
** EPITECH PROJECT, 2020
** nmatch tester
** File description:
** nmatch tester
*/

#include <criterion/criterion.h>

int match(char const *s1, char const *s2);

Test(match, test_match_star_at_end)
{
    const char s1[] = "abcdfezfz";
    const char s2[] = "ab*";
    int a = match(s1, s2);

    cr_assert_eq(a, 1);
}

Test(match, test_no_match)
{
    const char s1[] = "abcdfezfz";
    const char s2[] = "ad*";
    int a = match(s1, s2);

    cr_assert_eq(a, 0);
}

Test(match, test_star_at_start)
{
    const char s1[] = "abcdfezfz";
    const char s2[] = "ab**fd";
    int a = match(s1, s2);

    cr_assert_eq(a, 0);
}

Test(match, only_star)
{
    const char s1[] = "abcdfezfz";
    const char s2[] = "*";
    int a = match(s1, s2);

    cr_assert_eq(a, 1);
}
