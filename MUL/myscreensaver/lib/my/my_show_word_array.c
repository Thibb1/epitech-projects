/*
** EPITECH PROJECT, 2020
** show_word_array
** File description:
** show each word of arr
*/

int my_arrlen(char * const *tab);

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int s_tab = my_arrlen(tab);
    for (int i = 0; i < s_tab; i++) {
        for (int a = 0; tab[i][a]; a++)
            my_putchar(tab[i][a]);
        my_putchar('\n');
    }
    return (0);
}
