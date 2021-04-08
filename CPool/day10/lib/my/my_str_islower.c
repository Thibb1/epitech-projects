/*
** EPITECH PROJECT, 2020
** isonlylower
** File description:
** only alpha lower
*/

char my_is_down_case(char c);

int my_str_islower(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_down_case(str[i]))
            return (0);
    return (1);
}
