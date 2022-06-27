/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** copy n of src in dest
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (n > i) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
