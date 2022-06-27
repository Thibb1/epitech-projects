/*
** EPITECH PROJECT, 2020
** mystrncat
** File description:
** concatenates n characters of the str in dest
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[j])
        j++;
    for (i = 0; src[i] && nb > i; i++)
        dest[j + i] = src[i];
    dest[j + i] = '\0';
    return (dest);
}
