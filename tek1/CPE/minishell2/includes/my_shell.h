/*
** EPITECH PROJECT, 2020
** MY_SHELL.h
** File description:
** includes for MY_SHELL MY_SHELL
*/

#ifndef MY_SHELL
#define MY_SHELL
#include "my.h"
#define GET_STR_LIST(x, y, nb)                   \
while ((x != NULL) && my_strncmp(x->str, y, nb)) \
    x = x->next

typedef struct str_list {
    char *str;
    struct str_list *next;
} str_list;

typedef struct cmd_list {
    char **exec_arr;
    char *out;
    int out_type;
    int old_out;
    char *in;
    int in_type;
    int old_in;
    int pipe_fd[2];
    str_list *input;
    struct cmd_list *pipe;
    struct cmd_list *next;
} cmd_list;

extern str_list *env;
extern cmd_list *cmd;

/// @brief detects the type of call and runs a shell with or without prompt
int minishell(char **env);

/// @brief print the prompt and manages env init
int shell(bool prompt);

/// @brief gets the input and parse it to an array of strings
int shell_input(bool *should_exit);

/// @brief launch builtins / programs of one string
int shell_run(cmd_list *cur, bool *exit);

int shell_exit(int status, bool *ex, cmd_list *cur);

/// @brief parse the array to the shell_run
int shell_run_arr(bool *should_exit, int exit);

/// @brief parse the env to a linked list
str_list *init_env(char **env);

/// @brief builtin to print the env
int builtin_env(cmd_list *cur);
int builtin_setenv(char **cmd);
int builtin_unsetenv(char **cmd);
int my_setenv(char *env, char *str);
void show_env(void);

char **str_list_to_arr(str_list *head);
int str_count_words(const char *str, const char *separator);
char **str_to_arr(const char *str, const char *separator);
int str_list_len(str_list *head);

void str_list_head(str_list **head, char *str);
void str_list_push(str_list **head, char *str);
void str_list_free(str_list **head);
void str_list_pop(str_list **head);
void str_list_remove(str_list **head, int n);

char *my_grep_str(char reg, char *str);

int arr_len(char **arr);
void arr_free(char **arr);

int my_execve(cmd_list *cur, char **path, char **env_arr, bool *ex);

/// @brief runs builtins
int my_builtin(cmd_list *cur, bool *exit);

int builtin_exit(cmd_list *cur, bool *exit);
int builtin_cd(char **cmd);
int my_cd(char *cmd);
char *get_cd_path(char *cmd);
int file_exist(char *str);

int is_command(char *str);
int check_alphanum(char *str);
int check_num(char *str);
int is_builtin(char *str);
int check_input_arr(char **arr);

void signal_ctrl_c(int sig);
void signal_ctrl_z(int sig);
void my_prompt(void);

void cmd_parser(cmd_list *cur);
int parse_input(char **arr);
void cmd_list_free(void);

void open_in(cmd_list *cur);
void open_out(cmd_list *cur);
void close_out(cmd_list *cur);
void close_in(cmd_list *cur);

int run_cmd_piped(cmd_list *cur, bool *should_exit, int ret);
void print_cd_error(char *cmd, char *path, struct stat st);
#endif