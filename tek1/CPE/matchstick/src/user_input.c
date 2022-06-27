/*
** EPITECH PROJECT, 2020
** user_input.c
** File description:
** gets user input
*/

#include "match.h"

int get_user_line(settings *a)
{
    char *buf = NULL;
    size_t buf_size = 0;

    my_printf("Line: ");
    getline(&buf, &buf_size, stdin);
    if (buf[0] == 0)
        return (-1);
    for (int i = 0; buf[i]; i++)
        buf[i] = buf[i] == '\n' ? 0 : buf[i];
    if (only_num(buf)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (my_getnbr(buf) > a->li || my_getnbr(buf) <= 0) {
        my_printf("Error: this line is out of range\n");
        return (0);
    }
    return (my_getnbr(buf));
}

int check_match_nb(settings *a, int line, int ret, int *sticks)
{
    if (ret == 0)
        my_printf("Error: you have to remove at least one match\n");
    else if (ret > a->p) {
        my_printf("Error: you cannot remove more than %d ", a->p);
        my_printf("matches per turn\n");
        ret = 0;
    }
    if (ret > sticks[line - 1]) {
        my_printf("Error: not enough matches on this line\n");
        ret = 0;
    }
    return (ret);
}

int get_user_match(settings *a, int line, int *sticks)
{
    char *buf = NULL;
    size_t buf_size = 0;

    my_printf("Matches: ");
    getline(&buf, &buf_size, stdin);
    if (buf[0] == 0)
        return (-1);
    for (int i = 0; buf[i]; i++)
        buf[i] = buf[i] == '\n' ? 0 : buf[i];
    if (only_num(buf)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (0);
    }
    return (check_match_nb(a, line, my_getnbr(buf), sticks));
}

int user_out(settings *a, int *sticks, int match, int line)
{
    if (match == -1 || line == -1)
        return (0);
    sticks[line - 1] -= match;
    a->n -= match;
    my_printf("Player removed %d match(es) from line %d\n", match, line);
    if (a->n == 0) {
        print_sticks(a, sticks);
        my_printf("You lost, too bad...\n");
        return (2);
    }
    return (-1);
}

int user_input(settings *a, int *sticks)
{
    int line = 0;
    int match = 0;

    my_printf("\nYour turn:\n");
    do {
        do {
            line = get_user_line(a);
        } while (line == 0);
        if (line == -1)
            break;
        match = get_user_match(a, line, sticks);
    } while (match == 0);
    return (user_out(a, sticks, match, line));
}