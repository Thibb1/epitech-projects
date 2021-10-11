/*
** EPITECH PROJECT, 2020
** ia_inout.c
** File description:
** IA main logic / actions
*/

#include "match.h"

int check_win(int k, int lines, int *sticks)
{
    int nim_sum = sticks[0];
    int dual_sum = sticks[0];

    for (int i = 1; i < lines; i++) {
        nim_sum ^= sticks[i];
        dual_sum |= sticks[i];
    }
    dual_sum = dual_sum % (k + 1) == 1 ? 1 : 0;
    nim_sum = !nim_sum;
    return (dual_sum ^ nim_sum);
}

void ia_remove_stick(int *sticks)
{
    int line = 0;

    while (sticks[line++] == 0);
    sticks[line - 1]--;
    my_printf("AI removed 1 match(es) from line %d\n", line);
}

int remove_lines_ia(settings *a, int *sticks, int line)
{
    int rm = 0;

    while (rm < a->p && sticks[line] && !check_win(a->p, a->li, sticks)) {
        sticks[line] -= 1;
        rm++;
    }
    return (rm);
}

void ia_auto_win(settings *a, int *sticks)
{
    int line = rand() % a->li;
    int rm;
    int save;
    int loops = 0;

    while (!check_win(a->p, a->li, sticks) && loops++ < a->li * 2) {
        rm = 0;
        line = line % a->li;
        save = sticks[line];
        rm = remove_lines_ia(a, sticks, line);
        if (!check_win(a->p, a->li, sticks))
            sticks[line] = save;
    }
    if (loops > a->li) {
        ia_remove_stick(sticks);
        return;
    }
    my_printf("AI removed %d match(es) from line %d\n", rm, line + 1);
}

int ia_input(settings *a, int *sticks)
{
    int will_win = check_win(a->p, a->li, sticks);

    my_printf("\nAI's turn...\n");
    if (will_win) {
        ia_remove_stick(sticks);
    } else
        ia_auto_win(a, sticks);
    a->n = calc_n(a, sticks);
    if (a->n <= 0) {
        print_sticks(a, sticks);
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (-1);
}