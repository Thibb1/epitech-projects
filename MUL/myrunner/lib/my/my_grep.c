/*
** EPITECH PROJECT, 2020
** my_grep.c
** File description:
** returns True if exp found in src
*/

int my_grep(const char *exp, const char src)
{
    int found = 0;
    for (int i = 0; exp[i]; i++)
        found += exp[i] == src;
    return (found);
}
