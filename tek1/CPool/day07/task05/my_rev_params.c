/*
** EPITECH PROJECT, 2020
** argv printer
** File description:
** print argv of the call
*/

#include <unistd.h>

void my_putcharb(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int i = argc - 1;
    int a;

    for (; i + 1 > 0; i--) {
        for (a = 0; argv[i][a]; a++)
            my_putcharb(argv[i][a]);
        my_putcharb('\n');
    }
    return (0);
}
