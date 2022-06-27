/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** returns True if str is num
*/

int my_is_numone(char c)
{
    if (!(c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    return (1);
}
