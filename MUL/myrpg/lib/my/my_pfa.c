/*
** EPITECH PROJECT, 2020
** pfa.c
** File description:
** pointer on function utils
*/

#include "my_printf.h"

int d_process(int fd, va_list li, flag *flag, int count)
{
    int nb_buff = va_arg(li, int);
    int nb = nb_buff;
    int nb_size = 0;

    for (; nb_buff; nb_buff /= 10, nb_size++);
    nb_size += flag->precision - nb_size + (nb < 0 || flag->p);
    for (; !flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(fd, flag->f);
    count += nb < 0 ? my_putchar(fd, '-') : 0;
    count += nb >= 0 && flag->p ? my_putchar(fd, '+') : 0;
    for (nb_buff = nb, nb_size = 0; nb_buff; nb_buff /= 10, nb_size++);
    for (; flag->precision > nb_size; nb_size++)
        count += my_putchar(fd, '0');
    count += my_putnbr(fd, nb);
    for (; flag->m && flag->wide > nb_size; flag->wide--)
        count += my_putchar(fd, flag->f);
    return (count);
}

int c_process(int fd, va_list li, flag *flag, int count)
{
    for (; !flag->m && flag->wide > 1; flag->wide--)
        count += my_putchar(fd, ' ');
    count += my_putchar(fd, va_arg(li, int));
    for (; flag->m && flag->wide > 1; flag->wide--)
        count += my_putchar(fd, ' ');
    return (count);
}

int s_process(int fd, va_list li, flag *flag, int count)
{
    char *str = va_arg(li, char *);
    int s_length = my_strlen(str);

    if (flag->precision > 0)
        s_length -= s_length / flag->precision;
    for (; !flag->m && flag->wide > s_length; flag->wide--)
        count += my_putchar(fd, ' ');
    if (flag->dot)
        count += my_putnstr(fd, str, flag->precision);
    else
        count += my_putstr(fd, str);
    for (; flag->m && flag->wide > s_length; flag->wide--)
        count += my_putchar(fd, ' ');
    return (count);
}

int f_process(int fd, va_list li, flag *flag, int count)
{
    double nb = va_arg(li, double);
    int precision = !flag->precision && !flag->dot ? 6 : flag->precision;
    char *str = my_ftoa(nb, precision);
    int str_len = flag->p ? my_strlen(str) + 1 : my_strlen(str);

    for (; !flag->m && flag->wide > str_len; flag->wide--)
        count += my_putchar(fd, flag->f);
    count += flag->p ? my_putchar(fd, '+') : 0;
    count += my_dprintf(fd, "%s", str);
    for (; flag->m && flag->wide > str_len; flag->wide--)
        count += my_putchar(fd, flag->f);
    free(str);
    return (count);
}