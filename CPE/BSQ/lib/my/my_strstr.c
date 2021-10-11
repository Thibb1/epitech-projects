/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** return first occurance of to_find in str
*/

int my_isfirst(int j, int i, int n)
{
    if (j == 0)
        return (i);
    return (n);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int n = 0;

    for (;to_find[j] && str[i]; i++) {
        if (to_find[j] != str[i])
            j = 0;
        if (to_find[j] == str[i]) {
            n = my_isfirst(j, i, n);
            j++;
        }
    }
    if (!to_find[j])
        return (&str[n]);
    return (0);
}
