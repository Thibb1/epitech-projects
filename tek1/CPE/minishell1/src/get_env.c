/*
** EPITECH PROJECT, 2020
** get_env.c
** File description:
** sh funct
*/

#include "my_sh.h"

char *get_env_str(char *var, char **env)
{
    int i = 0;
    int len = my_strlen(var);

    for (; env[i]; i++) {
        if (!my_strncmp(var, env[i], len))
            return (&env[i][len + 1]);
    }
    return (NULL);
}

void builtin_unsetenv(char **cmd, char **env)
{
    if (arr_len(cmd) == 1)
        my_ferror("unsetenv: Too few arguments");
    for (int len = 1; cmd[len]; len++) {
        my_unsetenv(cmd[len], env);
    }
}

void builtin_setenv(char **cmd, char **env)
{
    int len = arr_len(cmd);

    if (len == 3) {
        my_unsetenv(cmd[1], env);
        my_setenv(cmd[1], cmd[2], env);
    } else if (len == 2) {
        my_unsetenv(cmd[1], env);
        my_setenv(cmd[1], "", env);
    } else
        print_arr(env);
}

void my_unsetenv(char *str, char **env)
{
    int len = 0;
    int clen = my_strlen(str);
    int a_len = arr_len(env) - 1;
    int bool_found = 0;

    for (; env[len]; len++) {
        if (!my_strncmp(str, env[len], clen)) {
            bool_found++;
            break;
        }
    }
    if (bool_found) {
        free(env[len]);
        env[len] = malloc(sizeof(char) * my_strlen(env[a_len]) + 1);
        env[len][0] = 0;
        my_strcpy(env[len], env[a_len]);
        env[a_len] = 0;
        free(env[a_len]);
    }
}

void my_setenv(char *str, char *val, char **env)
{
    int len = arr_len(env);
    int slen = my_strlen(str) + my_strlen(val) + 2;

    if ((env[len] = malloc(sizeof(char) * slen)) == NULL)
        exit(my_ferror("./mysh: malloc error"));
    my_strcat(env[len], str);
    my_strcat(env[len], "=");
    my_strcat(env[len], val);
}