/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** cmp s1 to s2
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while ((s1[i] || s2[i]) && n > i) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}
