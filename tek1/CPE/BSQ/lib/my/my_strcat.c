/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concatenates characters of the str in dest
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    for (;dest[j]; j++);
    for (; src[i]; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}
