/*
** EPITECH PROJECT, 2020
** argv printer
** File description:
** print argv of the call
*/

void my_putcharc(char c);

int my_strcmpb(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}

int my_min_nb(int j, int min_nb, char *argv[])
{
    if (my_strcmpb(argv[j], argv[min_nb]) < 0)
        return (j);
    return (min_nb);
}

void my_sort_char_array(int argc, char *argv[])
{
    int i = 0;
    int j;
    int min_nb;
    char *tampon;

    while (i < argc) {
        min_nb = i;
        for (j = i + 1; j < argc; j++)
            min_nb = my_min_nb(j, min_nb, argv);
        tampon = argv[min_nb];
        argv[min_nb] = argv[i];
        argv[i] = tampon;
        i++;
    }
}

int main(int argc, char *argv[])
{
    int i;
    int a;

    my_sort_char_array(argc, argv);
    for (i = 0; i < argc; i++) {
        for (a = 0; argv[i][a]; a++)
            my_putcharc(argv[i][a]);
        my_putcharc('\n');
    }
    return (0);
}
