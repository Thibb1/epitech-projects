/*
** EPITECH PROJECT, 2020
** check_map
** File description:
** check buff in map
*/

#include "../include/my.h"
#include "../include/navy.h"

int check_file(char buff[32])
{
    if (!(buff[0] == '2' && buff[1] == ':' && buff[4] == ':' && buff[9] == ':'
        && buff[12] == ':'))
        return (my_ferror("wrong map"));
    if (!(buff[8] == '3' && buff[17] == ':' && buff[20] == ':' &&
        buff[25] == ':'))
        return (my_ferror("wrong map"));
    if (!(buff[16] == '4' && buff[24] == '5'))
        return (my_ferror("wrong map"));
    return (check_vars(buff));
}

int check_vars(char buff[32])
{
    int ret = 0;

    ret += check_char(buff[2], buff[5]);
    ret += check_char(buff[10], buff[13]);
    ret += check_char(buff[18], buff[21]);
    ret += check_char(buff[26], buff[29]);
    ret += check_nb(buff[3], buff[6]);
    ret += check_nb(buff[11], buff[14]);
    ret += check_nb(buff[19], buff[22]);
    ret += check_nb(buff[27], buff[30]);
    return (ret);
}

int check_char(char a, char b)
{
    if (a < 'A' || a > 'H')
        return (my_ferror("wrong map"));
    if (b < 'A' || b > 'H')
        return (my_ferror("wrong map"));
    return (0);
}

int check_nb(char a, char b)
{
    if (a < '0' || a > '8')
        return (my_ferror("wrong map"));
    if (b < '0' || b > '8')
        return (my_ferror("wrong map"));
    return (0);
}