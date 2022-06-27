/*
** EPITECH PROJECT, 2020
** my_fscanf.c
** File description:
** extract data from file
*/

#include "my_printf.h"

void double_parse(int file, va_list li, char buff[3])
{
    double *b = va_arg(li, double *);
    int number = 0;
    char str[40] = "";

    for (; read(file, buff, 1) > 0;) {
        if (number && !my_grep("-0123456789.", buff[0]))
            break;
        if (my_grep("-0123456789.", buff[0])) {
            str[number++] = buff[0];
        }
    }
    str[number] = 0;
    *b = my_atof(str);
}

void short_parse(int file, va_list li, char buff[3])
{
    unsigned short *c = va_arg(li, unsigned short *);
    int number = 0;

    *c = 0;
    for (; read(file, buff, 1) > 0;) {
        if (number && !my_grep("0123456789", buff[0]))
            break;
        if (my_grep("0123456789", buff[0])) {
            number++;
            *c = *c * 10 + buff[0] - '0';
        }
    }
}

void int_parse(int file, va_list li, char buff[3])
{
    int *a = va_arg(li, int *);
    int number = 0;
    char str[30] = "";

    for (; read(file, buff, 1) > 0;) {
        if (number && !my_grep("-0123456789", buff[0]))
            break;
        if (my_grep("-0123456789", buff[0])) {
            str[number++] = buff[0];
        }
    }
    str[number] = 0;
    *a = my_atoi(str);
}

int format_parse(int file, const char c, va_list li)
{
    char buff[3];

    if (my_grep("di", c))
        int_parse(file, li, buff);
    if (my_grep("f", c))
        double_parse(file, li, buff);
    if (my_grep("s", c))
        short_parse(file, li, buff);
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
