/*
** EPITECH PROJECT, 2020
** my_sh.h
** File description:
** includes for my_sh binary
*/

#ifndef BINARY
#define BINARY

#define STARTUP 0
#define RUNNING 1

#define LINE_READ 1024

#include "my.h"
//
//  arr.c
//
int arr_len(char **arr);
char **copy_arr(char **arr);
void free_arr(char **arr);
void print_arr(char **arr);

//
//  builtin.c
//
int check_builtin(char *str);
void run_builtin(char **cmd, char **env);

//
//  cd.c
//
void builtin_cd(char **cmd, char **env);
void my_cd(char *path, char **env);
char *get_cd_path(char *cmd, char **env);

//
//  exec.c
//
void exec_tree(char *str, char **env);
void exec_cmd(char **cmd, char **env);
char *get_cmd_path(char const *path, char const *exec);

//
//  get_env.c
//
char *get_env_str(char *var, char **env);
void builtin_setenv(char **cmd, char **env);
void builtin_unsetenv(char **cmd, char **env);
void my_unsetenv(char *str, char **env);
void my_setenv(char *str, char *val, char **env);

//
//  my_sh.c
//
int my_sh(int ac, char **av, char **env);

//
//  prompt.c
//
void prompt(int mode, char **env);

//
//  simple_input.c
//
int one_command_input(char **av, char **env);
int tty_one_command(char **env);

//
//  str_to_arr.c
//
int str_count_words(const char *str, const char *separator);
char **str_to_arr(const char *str, const char *separator);

//
//  user_input.c
//
int user_shell(char **env);

#endif