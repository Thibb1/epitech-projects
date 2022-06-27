/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copyes a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (n > i) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
