/*
** EPITECH PROJECT, 2020
** navy_check.c
** File description:
** navy check arg
*/

#include "../include/my.h"
#include "../include/navy.h"

int check_av(int ac, char *av[])
{
    if (ac == 3 && !my_str_isnum(av[1]))
        return (my_ferror("Argument 1 must be a number. Try ./navy -h"));
    if (ac > 3 || ac < 2)
        return (my_ferror("Wrong nb of argument. Try ./navy -h"));
    return (0);
}

int check_help(int ac, char *av[])
{
    if (ac > 1 && !my_strcmp("-h", av[1])) {
        my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRI");
        my_printf("TION\n\tfirst_player_pid: only for the 2nd player. pid of");
        my_printf(" the first player.\n\tnavy_positions: file representing t");
        my_printf("he positions of the ships.\n");
        return (1);
    }
    return (0);
}