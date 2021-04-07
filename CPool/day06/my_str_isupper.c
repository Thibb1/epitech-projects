/*
** EPITECH PROJECT, 2020
** isupper
** File description:
** return 1 if not only upper
*/

int my_is_upper_one(char c)
{
    if (!(c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_upper_one(str[i]))
            return (0);
    return (1);
}
