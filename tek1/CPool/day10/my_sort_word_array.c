/*
** EPITECH PROJECT, 2020
** Sort_word_arr
** File description:
** sorts str in ascii order
*/

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

int my_min_nb(int j, int min_nb, char **argv)
{
    if (my_strcmpb(argv[j], argv[min_nb]) < 0)
        return (j);
    return (min_nb);
}

void my_sort_char_array(int argc, char **argv)
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

int my_sort_word_array(char **tab)
{
    int i = 0;
    for (; tab[i][0]; i++);
    my_sort_char_array(i, tab);
    return (0);
}
