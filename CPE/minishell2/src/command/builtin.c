/*
** EPITECH PROJECT, 2021
** builtin.c
** File description:
** check and runs builtin commands
*/

#include "my_shell.h"

int my_builtin(cmd_list *cur, bool *exit)
{
    if (!my_strcmp(cur->exec_arr[0], "cd"))
        return (builtin_cd(cur->exec_arr));
    if (!my_strcmp(cur->exec_arr[0], "setenv"))
        return (builtin_setenv(cur->exec_arr));
    if (!my_strcmp(cur->exec_arr[0], "unsetenv"))
        return (builtin_unsetenv(cur->exec_arr));
    if (!my_strcmp(cur->exec_arr[0], "env"))
        return (builtin_env(cur));
    if (!my_strcmp(cur->exec_arr[0], "exit"))
        return (builtin_exit(cur, exit));
    return (0);
}

int builtin_exit(cmd_list *cur, bool *exit)
{
    int len = arr_len(cur->exec_arr);

    if (len > 1) {
        if (check_num(cur->exec_arr[1]) == 1) {
            my_dprintf(2, "exit: Expression Syntax.\n");
            return (1);
        } else if (check_num(cur->exec_arr[1])) {
            my_dprintf(2, "exit: Badly formed number.\n");
            return (1);
        }
        *exit = true;
        return (my_atoi(cur->exec_arr[1]));
    }
    if (len > 2) {
        my_dprintf(2, "exit: Expression Syntax.\n");
        return (1);
    }
    *exit = true;
    return (0);
}

int builtin_setenv(char **cmd)
{
    int len = arr_len(cmd);

    if (len >= 2) {
        if (check_alphanum(cmd[1]) == 2) {
            my_dprintf(2, "setenv: Variable name must begin with a letter.\n");
            return (1);
        } else if (check_alphanum(cmd[1]) == 1) {
            my_dprintf(2, "setenv: Variable name must contain alphanumeric "
                "characters.\n");
        }
    }
    if (len == 3) {
        my_setenv(cmd[1], cmd[2]);
    } else if (len == 2)
        my_setenv(cmd[1], "");
    if (len > 3) {
        return (my_dprintf(2, "setenv: Too many arguments.\n") - 27);
    } else if (len == 1)
        show_env();
    return (0);
}

int builtin_unsetenv(char **cmd)
{
    int len = arr_len(cmd);
    str_list *cur = env;
    int n = 0;

    if (len == 1)
        return (my_dprintf(2, "unsetenv: Too few arguments.\n") - 28);
    for (int i = 1; i < len; i++) {
        if (check_alphanum(cmd[i]))
            break;
        cur = env;
        n = 0;
        for (; cur != NULL; n++) {
            if (!my_strncmp(cmd[i], cur->str, my_strlen(cmd[i]))) {
                str_list_remove(&env, n);
                break;
            }
            cur = cur->next;
        }
    }
    return (0);
}

int builtin_env(cmd_list *cur)
{
    if (cur->out)
        open_out(cur);
    show_env();
    if (cur->out)
        close_out(cur);
    return (0);
}