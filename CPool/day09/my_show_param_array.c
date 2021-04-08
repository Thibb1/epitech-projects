/*
** EPITECH PROJECT, 2020
** show_params_array
** File description:
** show params of struct
*/

#include "include/my.h"

#include <unistd.h>


int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str != NULL; i++) {
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_putstr(par[i].str);
        my_putchar('\n');
        my_putstr(par[i].copy);
        my_putchar('\n');
        my_putstr(concat_params(par[i].length, par[i].word_array));
        my_putchar('\n');
    }
    return (0);
}