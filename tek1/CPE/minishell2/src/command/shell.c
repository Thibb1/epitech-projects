/*
** EPITECH PROJECT, 2021
** shell.c
** File description:
** shell commands
*/

#include "my_shell.h"

void cmd_init(void)
{
    cmd = malloc(sizeof(cmd_list));
    cmd->next = NULL;
    cmd->exec_arr = NULL;
    cmd->in = NULL;
    cmd->out = NULL;
    cmd->input = NULL;
    cmd->next = NULL;
    cmd->pipe = NULL;
}

int shell_input(bool *should_exit)
{
    size_t size;
    char **arr = NULL;
    char *str = NULL;
    int idx = 0;
    int ret;

    if (getline(&str, &size, stdin) == EOF) {
        free(str);
        *should_exit = true;
        return (0);
    }
    cmd_init();
    idx = my_strlen(str) - 1;
    str[idx] = str[idx] == '\n' ? 0 : str[idx];
    arr = str_to_arr(str, ";");
    ret = parse_input(arr);
    arr_free(arr);
    free(str);
    return (ret);
}

int shell_run_arr(bool *should_exit, int exit)
{
    cmd_list *cur = NULL;

    if (shell_input(should_exit))
        return (exit);
    cur = cmd;
    while (!*should_exit && cur != NULL) {
        if (cur->pipe != NULL)
            exit = run_cmd_piped(cur, should_exit, 0);
        else if (cur->exec_arr != NULL)
            exit = shell_run(cur, should_exit);
        cur = cur->next;
    }
    return (exit);
}

int shell(bool prompt)
{
    int exit = 0;
    bool should_exit = false;

    signal(SIGTSTP, signal_ctrl_z);
    do {
        if (prompt)
            my_prompt();
        exit = shell_run_arr(&should_exit, exit);
        cmd_list_free();
    } while (should_exit == false);
    my_printf(prompt ? "exit\n" : "");
    str_list_free(&env);
    return (exit);
}

void my_prompt(void)
{
    str_list *user = env;
    str_list *name = env;
    str_list *pwd = env;
    str_list *home = env;

    GET_STR_LIST(user, "USER=", 5);
    GET_STR_LIST(name, "NAME=", 5);
    GET_STR_LIST(pwd, "PWD=", 4);
    GET_STR_LIST(home, "HOME=", 5);
    if (user != NULL)
        my_printf(GREEN "%s", my_grep_str('=', user->str));
    if (name != NULL)
        my_printf(user ? GREEN "@%s" WHITE ":" :
            GREEN "%s" WHITE ":", my_grep_str('=', name->str));
    if (pwd != NULL && home != NULL && !my_strncmp(my_grep_str('=', home->str),
        my_grep_str('=', pwd->str), my_strlen(my_grep_str('=', home->str))))
        my_printf(BLUE "~%s", &pwd->str[my_strlen(home->str) - 1]);
    else
        my_printf(BLUE "%s", pwd ? my_grep_str('=', pwd->str) : "");
    my_printf(WHITE "$ " RESET);
}