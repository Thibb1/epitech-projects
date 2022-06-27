/*
** EPITECH PROJECT, 2020
** isupper
** File description:
** return 1 if not only upper
*/

char my_is_up_case(char c);

int my_str_isupper(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (my_is_up_case(str[i]))
            return (0);
    return (1);
}
