/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copyes a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
