/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** init chained list
*/

#include "defender.h"

void pop_popup(assets *as, popup *cur)
{
    if (cur == NULL || !cur->t ||
        cur->t > sfTime_asSeconds(sfClock_getElapsedTime(cur->clock)))
        return;
    as->pop = cur->next;
    sfClock_destroy(cur->clock);
    sfText_destroy(cur->text);
    free(cur);
}

void remove_popup(assets *as, int n)
{
    popup *cur = as->pop;
    popup *temp = NULL;

    if (n == 0) {
        pop_popup(as, cur);
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (cur->next == NULL)
            return;
        cur = cur->next;
    }
    temp = cur->next;
    cur->next = temp->next;
    sfClock_destroy(temp->clock);
    sfText_destroy(temp->text);
    free(temp);
}

void popup_show(window *win, assets *as)
{
    popup *cur = as->pop;
    popup *next = NULL;
    int n = 0;

    while (cur != NULL) {
        next = cur->next;
        if (cur->scene == win->scene)
            sfRenderWindow_drawText(win->rw, cur->text, NULL);
        if (cur->t &&
            cur->t <= sfTime_asSeconds(sfClock_getElapsedTime(cur->clock))) {
            remove_popup(as, n--);
        }
        cur = next;
        n++;
    }
}

void set_popup(popup *cur, char *str, float f[3], int set[3])
{
    sfColor text_color = {255, 0, 255, 255};

    cur->clock = sfClock_create();
    cur->t = f[2];
    cur->scene = set[0];
    cur->text = sfText_create();
    sfText_setCharacterSize(cur->text, set[1]);
    if (set[2] == 0)
        sfText_setColor(cur->text, text_color);
    else if (set[2] == 1)
        sfText_setColor(cur->text, sfYellow);
    else
        sfText_setColor(cur->text, sfRed);
    sfText_setPosition(cur->text, (sfVector2f){f[0], f[1]});
    sfText_setString(cur->text, str);
}

void create_popup(assets *as, char *str, float f[3], int set[3])
{
    popup *head = as->pop;

    if (head == NULL) {
        as->pop = malloc(sizeof(popup));
        set_popup(as->pop, str, f, set);
        sfText_setFont(as->pop->text, as->font);
        as->pop->next = NULL;
    } else {
        while (head->next != NULL)
            head = head->next;
        head->next = malloc(sizeof(popup));
        set_popup(head->next, str, f, set);
        sfText_setFont(head->next->text, as->font);
        head->next->next = NULL;
    }
}
