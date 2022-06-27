/*
** EPITECH PROJECT, 2020
** isprintable
** File description:
** return 1 if only pritable
*/

int my_is_printable_one(char c)
{
    if (!(c >= ' ' && c <= '~'))
        return (1);
    return (0);
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_printable_one(str[i]))
            return (0);
    return (1);
}
