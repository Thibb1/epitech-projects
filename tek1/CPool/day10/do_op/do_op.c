/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** takes args and print calculation
*/

#include <unistd.h>
#include "include/my.h"

int do_op(char *argv[])
{
    int a = (argv[1]) ? my_getnbr(argv[1]) : 0;
    int b = (argv[3]) ? my_getnbr(argv[3]) : 0;
    int result = 0;
    char c = (argv[2] && argv[2][0]) ? argv[2][0] : 0;

    result = (c == 47) ? ((b) ? (a / b) : (12542))
        : ((c == 42) ? (a * b)
        : ((c == 43) ? a + b
        : ((c == 45) ? a - b
        : ((c == 37) ? ((b) ? (a % b) : (12543)) :0))));
    if (result == 12542) {
        write(2, "Stop: division by zero", 23);
    } else if (result == 12543) {
        write(2, "Stop: modulo by zero", 21);
    }
    return (result);
}

int main(int argc, char *argv[])
{
    int a = do_op(argv);
    argc++;
    if (a == 12542 || a == 12543)
        return (84);
    my_put_nbr(a);
    return (0);
}
