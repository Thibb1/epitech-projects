/*
** EPITECH PROJECT, 2020
** main_loop.c
** File description:
** basic loop that calls other loops
*/

#include "defender.h"

void enemy_spawn(assets *as, int nb)
{
    if (nb == 0)
        create_enemy(as->head, E_CIRCLE, sfRed);
    if (nb == 1)
        create_enemy(as->head, E_TRIANGLE, sfBlue);
    if (nb == 2)
        create_enemy(as->head, E_SQUARE, sfMagenta);
    else if (nb == 3)
        create_enemy(as->head, E_OCTAGON, sfWhite);
}

void text_gold_live(assets *as)
{
    char sc[1048] = "5/";
    char str[1048] = "";

    nb_to_str(sc, as->lives);
    nb_to_str(str, as->coins);
    sfText_setString(as->scenes[LVL].sh[1].text[2].text, sc);
    sfText_setString(as->scenes[LVL].sh[1].text[3].text, str);
}

void duck_idle(duck *dd)
{
    if (dd->rect.left == 0)
        dd->duck_state = 0;
    if (dd->rect.left == 220)
        dd->duck_state = 1;
    if (dd->duck_state == 0)
        dd->rect.left += 110;
    if (dd->duck_state == 1)
        dd->rect.left -= 110;
}

void game_loop(assets *as)
{
    float deltatime = sfTime_asSeconds(sfClock_restart(as->timer));
    int sec = sfTime_asSeconds(sfClock_getElapsedTime(as->s));

    if (sec >= 1) {
        sfClock_restart(as->s);
        as->current_s += 1;
        if (as->head == NULL)
            as->head = head_enemy(E_CIRCLE, sfRed);
        else
            enemy_spawn(as, as->current_s % 4);
        check_tower(as);
        check_head(as);
        text_gold_live(as);
        duck_idle(as->scenes[LVL].daffyduck);
    }
    enemy_move(as, deltatime);
}
