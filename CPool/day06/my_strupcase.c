/*
** EPITECH PROJECT, 2020
** strupcase
** File description:
** uppercasing
*/

char *my_strupcase(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ' ';
    return (str);
}
