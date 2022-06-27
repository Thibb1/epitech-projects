/*
** EPITECH PROJECT, 2020
** argv printer
** File description:
** print argv of the call
*/

#include <unistd.h>

void my_putchara(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int i;
    int a;

    for (i = 0; i < argc; i++) {
        for (a = 0; argv[i][a]; a++)
            my_putchara(argv[i][a]);
        my_putchara('\n');
    }
    return (0);
}
