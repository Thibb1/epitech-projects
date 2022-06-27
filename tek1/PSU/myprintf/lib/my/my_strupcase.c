/*
** EPITECH PROJECT, 2020
** my_strupcase.c
** File description:
** uppercasing of str
*/

char *my_strupcase(char *str)
{
    int i = 0;
    for (; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ' ';
    return (str);
}
