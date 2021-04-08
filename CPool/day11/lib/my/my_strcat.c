/*
** EPITECH PROJECT, 2020
** mystrcat
** File description:
** concatenates characters of the str in dest
*/

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;
    while (dest[j])
        j++;
    for (i = 0; src[i]; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}
