/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** will check some contents
*/

#include "my_shell.h"

int is_command(char *str)
{
    if (!my_strcmp("|", str))
        return (1);
    if (!my_strcmp(">", str))
        return (1);
    if (!my_strcmp(">>", str))
        return (1);
    if (!my_strcmp("<", str))
        return (1);
    if (!my_strcmp("<<", str))
        return (1);
    return (0);
}

int check_alphanum(char *str)
{
    if (!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z')) {
        return (2);
    }
    for (; *str; (void) *str++) {
        if ((*str >= '0' && *str <= '9') ||
            (*str >= 'A' && *str <= 'Z') ||
            (*str >= 'a' && *str <= 'z') ||
            *str == '_')
            continue;
        return (1);
    }
    return (0);
}

int check_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[0] == '-' && i == 0)
            continue;
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        return (i + 1);
    }
    return (0);
}

int check_input_arr2(char **arr, int x)
{
    if (!my_strcmp(arr[x], "|") && (!arr[x + 1] || is_command(arr[x + 1]))) {
        my_dprintf(2, "Invalid null command.\n");
        return (1);
    }
    if (!my_strcmp(arr[x], "<") || !my_strcmp(arr[x], "<<") ||
        !my_strcmp(arr[x], ">") || !my_strcmp(arr[x], ">>") ||
        !my_strcmp(arr[x], "|"))
        if (!arr[x + 1] || is_command(arr[x + 1])) {
            my_dprintf(2, "Missing name for redirect.\n");
            return (1);
        }
    return (0);
}

int check_input_arr(char **arr)
{
    int left = 0;
    int right = 0;

    for (int x = 0; arr[x]; left += !my_strcmp(arr[x], "|"), x++) {
        if (check_input_arr2(arr, x))
            return (1);
        if ((!my_strcmp(arr[x], "<") || !my_strcmp(arr[x], "<<")) &&
            ++left == 2) {
            my_dprintf(2, "Ambiguous input redirect.\n");
            return (1);
        } else if (((!my_strcmp(arr[x], ">") || !my_strcmp(arr[x], ">>")) &&
            ++right == 2) || (!my_strcmp(arr[x], "|") && right)) {
            my_dprintf(2, "Ambiguous output redirect.\n");
            return (1);
        }
    }
    return (0);
}