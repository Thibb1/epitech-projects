/*
** EPITECH PROJECT, 2020
** my_params_to_array
** File description:
** put params into arr of struc
*/

#include "include/my.h"

struct info_param *my_params_to_array(int ac, char **av )
{
    int i = 0;
    struct info_param *ret;

    if (ac) {
        ret = malloc(sizeof(struct info_param *) * ac);
        for (; i < ac; i++) {
            ret[i].length = my_strlen(av[i]);
            ret[i].str = malloc(sizeof(char) * ret[i].length);
            ret[i].copy = malloc(sizeof(char) * ret[i].length);
            my_strcat(ret[i].str, av[i]);
            my_strcat(ret[i].copy, av[i]);
            ret[i].word_array = my_str_to_word_array(av[i]);
        }
        return (ret);
    }
    return (((void*)0));
}