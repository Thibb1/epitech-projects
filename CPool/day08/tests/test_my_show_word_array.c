/*
** EPITECH PROJECT, 2020
** test_my_show_word_array
** File description:
** test show word arr
*/

#include <criterion/criterion.h>

int my_show_word_array(char * const *tab);

Test(my_show_word_array, tab_many_words)
{
    char *str[] = {"Coucou", " whatsupp", "Aime", "tu", "manger?", 0};
    cr_assert_eq(my_show_word_array(str), 0);
}
