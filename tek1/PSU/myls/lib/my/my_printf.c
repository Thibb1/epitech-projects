/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** prints str and args
*/

#include "../../include/my.h"
#include "../../include/myprintf.h"

int (*pfa[177])(va_list li, flag *flag, int count);

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
            count += flag_process(li, &flag, flag.spe);
        } else
            count += my_putchar(ag[i]);
    }
    va_end(li);
    return (count);
}

void init_pfa(void)
{
    pfa[(int)'c'] = c_process;
    pfa[(int)'d'] = d_process;
    pfa[(int)'i'] = d_process;
    pfa[(int)'o'] = b_process;
    pfa[(int)'u'] = b_process;
    pfa[(int)'x'] = b_process;
    pfa[(int)'X'] = b_process;
    pfa[(int)'b'] = b_process;
    pfa[(int)'p'] = p_process;
    pfa[(int)'s'] = s_process;
    pfa[(int)'S'] = s_process;
}

int flag_process(va_list li, flag *flag, char a)
{
    int count = 0;
    if (flag->s)
        count += my_putchar(' ');
    if (my_grep("cdiouxXbpsS", a))
        count += (*pfa[(int)a]) (li, flag, 0);
    else
        count += my_putchar('%');
    return (count);
}
