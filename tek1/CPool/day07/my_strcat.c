/*
** EPITECH PROJECT, 2020
** mystrcat
** File description:
** concatenates characters of the str in dest
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[j])
        j++;
    for (i = 0; src[i]; i++)
        dest[j + i] = src[i];
    dest[j + i] = '\0';
    return (dest);
}
