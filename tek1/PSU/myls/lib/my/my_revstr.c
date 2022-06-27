/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** copyes a string into another
*/

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    char c;

    for (; str[n]; n++);
    n--;
    while (i < n - i) {
        c = str[n - i];
        str[n - i] = str[i];
        str[i] = c;
        i++;
    }
    return (str);
}
