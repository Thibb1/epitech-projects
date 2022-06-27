/*
** EPITECH PROJECT, 2020
** strlowcase
** File description:
** lower case for cap case
*/

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ' ';
    return (str);
}
