/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** concetenate strs in 1 str
*/

#include <stdlib.h>

#include "include/my.h"

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int b = 0;
    int s_ret = 0;
    char *ret;

    for (int y = 0; y < argc; y++)
        s_ret += 1 + my_strlen(argv[i]);
    ret = malloc(sizeof(char) * s_ret);
    for (int a = 0; i < argc; i++, a++) {
        b += 1 + my_strlen(argv[i]);
        for (int c = 0; a < b - 1; a++, c++)
            ret[a] = argv[i][c];
        if (i < argc - 1)
            ret[b - 1] = '\n';
    }
    b++;
    ret[b] = '\0';
    return (ret);
}
