/*
** EPITECH PROJECT, 2020
** flag.c
** File description:
** flag managment
*/

#include "../../include/my.h"
#include "../../include/myprintf.h"

int flag_parse(const char *str, flag *flag, int count)
{
    for (; my_grep(" #0+-", str[count]) && str[count]; count++) {
        flag->p += my_grep("+", str[count]);
        flag->m += my_grep("-", str[count]);
        flag->h += my_grep("#", str[count]);
        flag->f = flag->m ? ' ' : flag->f;
        flag->f = !flag->m && '0' == str[count] ? '0' : flag->f;
        flag->s = !flag->m && !flag->p && !flag->h && str[count] == ' '
            && my_grep("cdiouxXpbsS", str[count + 1]) ? 1 : 0;
    }
    for (; my_grep("0123456789", str[count]) && str[count]; count++)
        flag->wide = flag->wide * 10 + str[count] - 48;
    for (; my_grep(".", str[count]) && str[count]; count++)
        flag->dot += 1;
    for (; my_grep("0123456789", str[count]) && str[count]; count++)
        flag->precision = flag->precision * 10 + str[count] - 48;
    if (flag->dot < 2 && my_grep("%cdiouxXpbsS", str[count]) && str[count])
        flag->spe = str[count++];
    else
        count = flag_reset(flag);
    return (count);
}

int flag_reset(flag *flag)
{
    flag->f = ' ';
    flag->spe = 0;
    flag->s = 0;
    flag->h = 0;
    flag->p = 0;
    flag->m = 0;
    flag->dot = 0;
    flag->wide = 0;
    flag->precision = 0;
    return (0);
}

int base_finder(const char c)
{
    if (my_grep("xX", c))
        return (16);
    if (c == 'b')
        return (2);
    if (c == 'o')
        return (8);
    return (10);

}

int hex_process(flag *flag, int nb_size, int count)
{
    if (flag->h && nb_size) {
        if ('x' == flag->spe)
            count += my_putstr("0x");
        else if ('X' == flag->spe)
            count += my_putstr("0X");
        else
            count += my_putchar('0');
    }
    return (count);
}
