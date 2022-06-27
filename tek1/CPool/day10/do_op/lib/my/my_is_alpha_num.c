/*
** EPITECH PROJECT, 2020
** my_is_alpha_num
** File description:
** returns 1 if alphanum
*/

int my_is_alpha_one(char c);

int my_is_alpha_num(char c)
{
    if (!(my_is_alpha_one(c)) || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}
