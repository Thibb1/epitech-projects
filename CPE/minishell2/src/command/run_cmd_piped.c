/*
** EPITECH PROJECT, 2021
** run_cmd_piped.c
** File description:
** manages pipe system
*/

#include "my_shell.h"

void pipe_start(cmd_list *cur, bool *should_exit)
{
    cur->old_out = dup(1);
    cur->old_in = dup(0);
    pipe(cur->pipe_fd);
    dup2(cur->pipe_fd[1], 1);
    shell_run(cur, should_exit);
}

int run_cmd_piped(cmd_list *cur, bool *should_exit, int ret)
{
    cmd_list *prev = cur;
    cmd_list *first_cur = cur;
    pipe_start(first_cur, should_exit);
    while (cur->pipe != NULL) {
        cur = cur->pipe;
        pipe(cur->pipe_fd);
        close(prev->pipe_fd[1]);
        dup2(prev->pipe_fd[0], 0);
        if (cur->pipe != NULL)
            dup2(cur->pipe_fd[1], 1);
        else
            dup2(first_cur->old_out, 1);
        ret = shell_run(cur, should_exit);
        close(prev->pipe_fd[0]);
        prev = cur;
    }
    close(cur->pipe_fd[1]);
    close(first_cur->pipe_fd[0]);
    dup2(first_cur->old_in, 0);
    return (ret);
}