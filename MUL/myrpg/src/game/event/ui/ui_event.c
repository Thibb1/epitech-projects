/*
** EPITECH PROJECT, 2021
** ui_event.c
** File description:
** ui_event.c
*/

#include "my_rpg.h"

void fight_ui_event(my_rpg *rpg, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
    rpg->ui.fight.back.state == HOVER) {
        sfSound_play(rpg->ui.audio.click);
        rpg->mode = 1;
        rpg->ui.disp_fight = sfFalse;
        rpg->quest.state = rpg->quest.state == 3 ? 4 : rpg->quest.state;
    }
}

void ui_event(my_rpg *rpg, sfEvent event)
{
    if (rpg->ui.disp_menu == sfTrue)
        menu_ui_event(rpg, event);
    if (rpg->ui.disp_menu == sfFalse && rpg->ui.disp_fight == sfFalse)
        game_ui_event(rpg, event);
    if (rpg->ui.disp_fight == sfTrue)
        fight_ui_event(rpg, event);
}