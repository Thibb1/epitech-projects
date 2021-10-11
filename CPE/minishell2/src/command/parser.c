/*
** EPITECH PROJECT, 2021
** parser.c
** File description:
** parse input
*/

#include "my_shell.h"

void parse_redirection(cmd_list *cur, char **arr, int *x)
{
    if (!my_strcmp(arr[*x], "<") || !my_strcmp(arr[*x], "<<")) {
        cur->in_type = !my_strcmp(arr[*x], "<") ? 1 : 0;
        cur->in = my_strdup(arr[*x + 1]);
        *x += 2;
    }
    if (arr[*x] == NULL)
        return;
    if (!my_strcmp(arr[*x], ">") || !my_strcmp(arr[*x], ">>")) {
        cur->out_type = !my_strcmp(arr[*x], ">") ? 1 : 0;
        cur->out = my_strdup(arr[*x + 1]);
        *x += 2;
    }
}

cmd_list *parse_pipe(cmd_list *cur, char **arr, int *x)
{
    cmd_list *next = cur;

    if (arr[*x] == NULL)
        return (cur);
    if (!my_strcmp(arr[*x], "|")) {
        cur->pipe = malloc(sizeof(cmd_list));
        next = cur->pipe;
        next->exec_arr = NULL;
        next->in = NULL;
        next->out = NULL;
        next->input = NULL;
        next->next = NULL;
        next->pipe = NULL;
        *x += 1;
    }
    return (next);
}

int init_cmd(char **cmd_arr, cmd_list *cur)
{
    if (check_input_arr(cmd_arr)) {
        arr_free(cmd_arr);
        return (1);
    }
    for (int x = 0; cmd_arr[x];) {
        parse_redirection(cur, cmd_arr, &x);
        cur = parse_pipe(cur, cmd_arr, &x);
        if (cmd_arr[x] != NULL && !is_command(cmd_arr[x]))
            str_list_push(&cur->input, cmd_arr[x++]);
    }
    arr_free(cmd_arr);
    return (0);
}

void list_to_arr(cmd_list *cur)
{
    if (cur->input != NULL)
        cur->exec_arr = str_list_to_arr(cur->input);
    while (cur->pipe != NULL && cur->pipe->input != NULL) {
        cur->pipe->exec_arr = str_list_to_arr(cur->pipe->input);
        cur = cur->pipe;
    }
}

int parse_input(char **arr)
{
    cmd_list *cur = cmd;

    for (int i = 0; arr[i]; i++) {
        cur->next = NULL;
        if (i > 0) {
            cur->next = malloc(sizeof(cmd_list));
            cur = cur->next;
        }
        cur->exec_arr = NULL;
        cur->in = NULL;
        cur->out = NULL;
        cur->input = NULL;
        cur->next = NULL;
        cur->pipe = NULL;
        if (init_cmd(str_to_arr(arr[i], " \t"), cur))
            return (1);
        list_to_arr(cur);
        cmd = i == 0 ? cur : cmd;
    }
    return (0);
}