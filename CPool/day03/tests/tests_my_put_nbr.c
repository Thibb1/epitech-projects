/*
** EPITECH PROJECT, 2020
** Main calling functions
** File description:
** test functions
*/

void my_putchar(char c);

int my_put_nbr(int nb);

int main(int argc, char *argv[])
{
    my_put_nbr(-10);
    my_put_nbr(2147483647);
    my_put_nbr(0);
    my_put_nbr(-200);
    my_put_nbr(467);
    my_put_nbr(-2147483648);
    return 0;
}
