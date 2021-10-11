/*
** EPITECH PROJECT, 2021
** shell_exec.c
** File description:
** execve functs
*/

#include "my_shell.h"

void my_execve_path(cmd_list *cur, char **path, char **env_arr)
{
    char *str = NULL;
    int cmd_len = my_strlen(cur->exec_arr[0]);

    for (int i = 0; path[i]; i++) {
        if (m_check(str = malloc(sizeof(char) *
            (my_strlen(path[i]) + cmd_len) + 2)))
            exit(FAILURE);
        str[0] = '\0';
        my_strcat(my_strcat(my_strcat(str, path[i]), "/"), cur->exec_arr[0]);
        execve(str, cur->exec_arr, env_arr);
        free(str);
    }
}

int my_execve(cmd_list *cur, char **path, char **env_arr, bool *ex)
{
    pid_t parent;
    int status = 0;

    cmd_parser(cur);
    if ((parent = fork()) == -1) {
        *ex = true;
        return (my_ferror("./minishell: fork error."));
    } else if (!parent) {
        execve(cur->exec_arr[0], cur->exec_arr, env_arr);
        my_execve_path(cur, path, env_arr);
        my_dprintf(2, "%s: Command not found.\n", cur->exec_arr[0]);
        cmd_list_free();
        str_list_free(&env);
        arr_free(env_arr);
        arr_free(path);
        exit(1);
    } else
        if (cur->pipe == NULL && wait(&status) == -1)
            exit(my_ferror("./minishell: wait error."));
    return (shell_exit(status, ex, cur));
}

int shell_error(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        if (WCOREDUMP(status))
            my_dprintf(2, "Segmentation fault (core dumped)\n");
        else
            my_dprintf(2, "Segmentation fault\n");
        return (139);
    }
    if (WTERMSIG(status) == SIGFPE) {
        if (WCOREDUMP(status))
            my_dprintf(2, "Floating exception (core dumped)\n");
        else
            my_dprintf(2, "Floating exception\n");
        return (136);
    }
    return (1);
}

int shell_exit(int status, bool *ex, cmd_list *cur)
{
    if (cur->in)
        close_in(cur);
    if (cur->out)
        close_out(cur);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        return (shell_error(status));
    if (WEXITSTATUS(status) == FAILURE) {
        *ex = true;
        return (84);
    }
    return (0);
}
