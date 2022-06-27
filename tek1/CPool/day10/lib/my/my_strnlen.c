/*
** EPITECH PROJECT, 2020
** my_strnlen
** File description:
** size of one word str
*/

int my_is_alpha_num(char c);

int my_strnlen(char const *str)
{
    int i = 0;

    for (; my_is_alpha_num(str[i]); i++);
    return (i);
}
