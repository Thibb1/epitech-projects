/*
** EPITECH PROJECT, 2021
** generator.c
** File description:
** generator main function
*/

#include "generator.h"

int generator(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (my_ferror("./generator: wrong number of args"));
    if (!positive_int(av[1]) || !positive_int(av[2]))
        return (my_ferror("./generator: x and y should be positive integers"));
    if (ac == 4) {
        if (!my_strcmp("perfect", av[3]))
            return (generator_perfect(my_atoi(av[1]), my_atoi(av[2])));
        else if (!my_strcmp("imperfect", av[3]))
            return (generator_imperfect(my_atoi(av[1]), my_atoi(av[2])));
    } else
        return (generator_imperfect(my_atoi(av[1]), my_atoi(av[2])));
    return (FAILURE);
}