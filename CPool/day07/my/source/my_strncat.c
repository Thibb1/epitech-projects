/*
** EPITECH PROJECT, 2020
** mystrncat
** File description:
** concatenates n characters of the str in dest
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int j = my_strlen(dest);

    for (i = 0; src[i] && nb > i; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}
