/*
** EPITECH PROJECT, 2020
** my_grep.c
** File description:
** returns True if exp found in src
*/

int my_grep(const char *str, const char c)
{
    int found = 0;

    while (*str)
        found += *str++ == c;
    return (found);
}
