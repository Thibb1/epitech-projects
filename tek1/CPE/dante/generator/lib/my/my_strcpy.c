/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** copy src in dest
*/

char *my_strcpy(char *dest, char const *src)
{
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (*src && n > i++)
        *dest++ = *src++;
    return (dest);
}