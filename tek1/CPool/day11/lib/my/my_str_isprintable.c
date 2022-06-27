/*
** EPITECH PROJECT, 2020
** isprintable
** File description:
** return 1 if only pritable
*/

int my_is_printable(char c);

int my_str_isprintable(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_printable(str[i]))
            return (0);
    return (1);
}
