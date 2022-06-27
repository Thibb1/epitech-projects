/*
** EPITECH PROJECT, 2020
** my_fscanf.c
** File description:
** extract data from file
*/

#include "../include/my.h"
#include "../include/myprintf.h"

int format_parse(int file, const char c, va_list li)
{
    int *a = va_arg(li, int *);
    char buff[2];

    if (my_grep("di", c))
        for (int i = 0; i < 1024 && read(file, buff, 1) > 0 &&
            !my_grep(" \n", buff[0]); i++)
            *a = *a * 10 + buff[0] - 48;
    return (1);
}

int my_fscanf(int file, const char *format, ...)
{
    va_list li;
    int ac = 0;

    va_start(li, format);
    for (int i = 0; format[i] && ac < MAX_ARGS; i++)
        if (format[i] == '%')
            ac += format_parse(file, format[++i], li);
    va_end(li);
    if (ac == 0)
        return (-1);
    return (ac);
}
