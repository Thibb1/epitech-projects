/*
** EPITECH PROJECT, 2020
** isalpha
** File description:
** only alpha nb
*/

int my_is_alpha_one(char c)
{
    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_alpha_one(str[i]))
            return (0);
    return (1);
}
