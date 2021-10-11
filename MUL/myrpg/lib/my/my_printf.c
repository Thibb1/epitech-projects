/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** prints str and args
*/

#include "my_printf.h"

int (*pfa[116])(int fd, va_list li, flag *flag, int count);

int my_printf(const char *ag, ...)
{
    va_list li;
    flag flag;
    int ac = 0;
    int count = 0;

    init_pfa();
    va_start(li, ag);
    for (int i = 0; ag[i] && ac < MAX_ARGS; i++) {
        if (ag[i] == '%') {
            i += flag_parse(&ag[i + 1], &flag, flag_reset(&flag));
            count += flag_process(STDOUT_FILENO, li, &flag, flag.spe);
        } else
            count += my_putchar(STDOUT_FILENO, ag[i]);
    }
    va_end(li);
    return (count);
}

void init_pfa(void)
{
    pfa[(int)'c'] = c_process;
    pfa[(int)'d'] = d_process;
    pfa[(int)'f'] = f_process;
    pfa[(int)'s'] = s_process;
}

int flag_process(int fd, va_list li, flag *flag, char a)
{
    int count = 0;

    if (flag->s)
        count += my_putchar(fd, ' ');
    if (my_grep("cdfs", a))
        count += (*pfa[(int)a]) (fd, li, flag, 0);
    else
        count += my_putchar(fd, '%');
    return (count);
}
