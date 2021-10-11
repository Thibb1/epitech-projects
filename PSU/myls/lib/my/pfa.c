/*
** EPITECH PROJECT, 2020
** pfa.c
** File description:
** pointer on function utils
*/

#include "../../include/my.h"
#include "../../include/myprintf.h"

int p_process(va_list li, flag *flag, int count)
{
    int nb_size = 8;

    for (; !flag->m && flag->wide > nb_size && flag->f == ' '; flag->wide--)
        count += my_putchar(flag->f);
    for (; !flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(flag->f);
    count += my_printf("%#x", va_arg(li, void *));
    for (; flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(flag->f);
    return (count);
}

int b_process(va_list li, flag *flag, int count)
{
    unsigned int nb_buff = va_arg(li, unsigned int);
    unsigned int nb = nb_buff;
    int base_size = base_finder(flag->spe);
    int nb_size = 0;

    for (; nb_buff; nb_buff /= base_size, nb_size++);
    if (flag->h && my_grep("xXo", flag->spe))
        nb_size += (flag->spe == 'o') ? 1 : 2;
    for (; !flag->m && flag->wide > nb_size && flag->f == ' '; flag->wide--)
        count += my_putchar(flag->f);
    count += hex_process(flag, nb_size, 0);
    for (; !flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(flag->f);
    count += b_put(nb, flag->spe, 0);
    for (; flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(flag->f);
    return (count);
}

int d_process(va_list li, flag *flag, int count)
{
    int nb_buff = va_arg(li, int);
    int nb_size = 0;
    int nb = nb_buff;

    for (; nb_buff; nb_buff /= 10, nb_size++);
    if (nb < 0) {
        count += my_putchar('-');
        nb_size++;
    } else if (flag->p) {
        count += my_putchar('+');
        nb_size++;
    }
    for (; !flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(flag->f);
    count += my_putnbr(nb);
    for (; flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(flag->f);
    return (count);
}

int c_process(va_list li, flag *flag, int count)
{
    for (; !flag->m && flag->wide > 1; flag->wide--)
        count += my_putchar(' ');
    count += my_putchar(va_arg(li, int));
    for (; flag->m && flag->wide > 1; flag->wide--)
        count += my_putchar(' ');
    return (count);
}

int s_process(va_list li, flag *flag, int count)
{
    char *str = va_arg(li, char *);
    int s_lenght = my_strlen(str);
    if (flag->precision)
        s_lenght -= s_lenght / flag->precision;
    for (; !flag->m && flag->wide > s_lenght; flag->wide--)
        count += my_putchar(' ');
    if ('s' == flag->spe)
        if (flag->dot)
            count += my_putnstr(str, flag->precision);
        else
            count += my_putstr(str);
    else
        if (flag->dot)
            count += my_shownstr(str, flag->precision);
        else
            count += my_showstr(str);
    for (; flag->m && flag->wide > s_lenght; flag->wide--)
        count += my_putchar(' ');
    return (count);
}
