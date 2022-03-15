/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** calls main funct
*/

#include "defender.h"

int print_help(void)
{
    my_printf("USAGE\n\t./my_defender\nDESCRIPTION:\n\tESC\tPause the game\n");
    my_printf("\tMOUSE_CLICK\tInteract with the game window\nGOAL:\n");
    my_printf("\tTOWERS\tPlace them to protect your castle\n\tCOINS\t");
    my_printf("Use them to buy towers or to upgrade towers efficiency\n\t");
    my_printf("LIVES\tTry to keep them as long as possible you lose if they ");
    my_printf("reach 0\n");
    return (SUCCESS);
}

int main(int ac, char const *av[], char *const *env)
{
    if (ac == 2 && !my_strcmp("-h", av[1]))
        return (print_help());
    return (my_defender());
}
