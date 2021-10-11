/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** calls main funct
*/

#include "my_rpg.h"

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    if (env == NULL)
        return (84);
    srand(time(NULL));
    start_rpg();
    return (SUCCESS);
}