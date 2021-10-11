/*
** EPITECH PROJECT, 2020
** exec.c
** File description:
** sh funct
*/

#include "my_sh.h"

void exec_tree(char *str, char **env)
{
    char **cmd = str_to_arr(str, " ");

    if (cmd == NULL || cmd[0] == NULL)
        return;
    if (check_builtin(cmd[0]))
        run_builtin(cmd, env);
    else
        exec_cmd(cmd, env);
    free_arr(cmd);
}

void exec_cmd(char **cmd, char **env) {
    int status = 0;
    pid_t child = fork();
    char *cmd_path = NULL;
    char **path = str_to_arr(get_env_str("PATH", env), ":");

    if (child == -1) {
        exit(my_ferror("./mysh: fork error."));
    } else if (!child) {
        execve(cmd[0], cmd, env);
        for (int i = 0; path[i]; i++) {
            cmd_path = get_cmd_path(path[i], cmd[0]);
            execve(cmd_path, cmd, env);
            free(cmd_path);
        }
        my_printf("%s: Command not found.\n", cmd[0]);
        exit(1);
    } else
        if (wait(&status) == -1)
            exit(my_ferror("./mysh: wait error."));
    if (WTERMSIG(status) == SIGSEGV)
        my_ferror("Segmentation fault (core dumped)");
    if (WIFEXITED(status) && WEXITSTATUS(status))
        exit(WEXITSTATUS(status));
}

char *get_cmd_path(char const *path, char const *exec)
{
    char *cmd;

    if ((cmd = malloc(sizeof(char) * (my_strlen(path) + my_strlen(exec)
        + 2))) == NULL)
        exit(my_ferror("./mysh: malloc error."));
    cmd[0] = 0;
    my_strcat(cmd, path);
    my_strcat(cmd, "/");
    my_strcat(cmd, exec);
    return (cmd);
}