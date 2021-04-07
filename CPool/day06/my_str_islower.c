/*
** EPITECH PROJECT, 2020
** isonlylower
** File description:
** only alpha lower
*/

int my_is_lower_one(char c)
{
    if (!(c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_lower_one(str[i]))
            return (0);
    return (1);
}
