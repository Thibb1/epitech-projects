/*
** EPITECH PROJECT, 2020
** isnum
** File description:
** only num nb
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    return (1);
}
