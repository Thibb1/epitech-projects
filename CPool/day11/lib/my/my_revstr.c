/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** copyes a string into another
*/

char *my_revstr(char *str)
{
    int i;
    int n;
    char c;

    i = 0;
    for (n = 0; str[n]; n++);
    n--;
    while (i < n - i) {
        c = str[n - i];
        str[n - i] = str[i];
        str[i] = c;
        i++;
    }
    return (str);
}
