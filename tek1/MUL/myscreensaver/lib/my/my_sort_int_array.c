/*
** EPITECH PROJECT, 2020
** my_sort_int_arr
** File description:
** sort arr in ascending order
*/

void my_putchar(char c);

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;
    int tampon;
    int min_nb;

    i = 0;
    while (i < size - 1) {
        min_nb = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[min_nb])
                min_nb = j;
        tampon = array[min_nb];
        array[min_nb] = array[i];
        array[i] = tampon;
        i++;
    }
}
