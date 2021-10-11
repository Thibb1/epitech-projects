/*
** EPITECH PROJECT, 2020
** my_sh.c
** File description:
** sh funct
*/

#include "my_sh.h"

int my_sh(int ac, char **av, char **env_old)
{
    char **env = copy_arr(env_old);

    if (ac == 2) {
        return (one_command_input(av, env));
    } else if (ac == 1)  {
        if (isatty(STDIN_FILENO))
            return (user_shell(env));
        else
            return (tty_one_command(env));
    }
    return (my_ferror("./mysh: wrong number of arguments"));
}