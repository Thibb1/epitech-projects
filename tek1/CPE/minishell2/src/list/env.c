/*
** EPITECH PROJECT, 2021
** env.c
** File description:
** env load / set / change
*/

#include "my_shell.h"

str_list *init_env(char **env)
{
    str_list *node = NULL;

    for (int i = 0; env[i] != NULL; i++)
        str_list_push(&node, env[i]);
    return (node);
}

int str_list_len(str_list *head)
{
    int len = 0;

    while (head != NULL) {
        head = head->next;
        len++;
    }
    return (len);
}

char **str_list_to_arr(str_list *head)
{
    int len = str_list_len(head) + 1;
    int j = 0;
    char **arr = NULL;

    if (len == 1 || m_check(arr = malloc(sizeof(char *) * len)))
        return (NULL);
    for (; head != NULL && j < len - 1; j++) {
        if (m_check(arr[j] = malloc(sizeof(char) * my_strlen(head->str) + 1)))
            return (NULL);
        arr[j][0] = 0;
        my_strcat(arr[j], head->str);
        head = head->next;
    }
    arr[j] = NULL;
    return (arr);
}

int my_setenv(char *env_str, char *str)
{
    str_list *cur = env;
    char *new_env = NULL;
    int len = my_strlen(str) + my_strlen(env_str) + 2;

    m_check(new_env = malloc(sizeof(char) * len));
    new_env[0] = 0;
    my_strcat(my_strcat(my_strcat(new_env, env_str), "="), str);
    while (cur != NULL && my_strncmp(cur->str, env_str, my_strlen(env_str)))
        cur = cur->next;
    if (cur == NULL || my_strncmp(cur->str, env_str, my_strlen(env_str))) {
        str_list_push(&env, new_env);
        free(new_env);
        return (0);
    }
    free(cur->str);
    cur->str = new_env;
    return (0);
}

void show_env(void)
{
    str_list *cur = env;

    while (cur != NULL) {
        my_printf("%s\n", cur->str);
        cur = cur->next;
    }
}