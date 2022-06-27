/*
** EPITECH PROJECT, 2020
** load_calls.c
** File description:
** calls game loading
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

static void player_state(object *p, game_data *game)
{
    sfIntRect rect = {0, 32 * p->state, 32, 32};

    p->current_sprite += 25.f * game->elapsed;
    if (p->state == IDLE)
        rect.left = ((int)p->current_sprite % 6) * 32;
    if (p->state == WALK)
        rect.left = ((int)p->current_sprite % 8) * 32;
    if (p->state == RUN)
        rect.left = ((int)p->current_sprite % 6) * 32;
    if (p->state == FLY)
        rect.left = ((int)p->current_sprite % 2) * 32;
    if (p->state == JUMP) {
        rect.left = ((int)p->current_sprite / 2 % 3) * 32;
        if ((int)p->current_sprite / 2 % 3 == 2) {
            p->state = FLY;
        }
    }
    sfSprite_setTextureRect(p->sprite, rect);
}

void check_collision(object *o, game_data *game, sfVector2f p)
{
    o->position = sfSprite_getPosition(o->sprite);
    if (160 > o->position.x && 188 < o->position.x + 128)
        if (p.y + 25 > o->position.y && p.y + 100 < o->position.y + 128)
            game->state = LOOSE;
}

void score_change(float s, game_data *game)
{
    char sc[1048] = "";
    int i = 0;

    for (; s >= 1; s /= 10, i++)
        sc[i] = (int)s % 10 + '0';
    sc[i] = 0;
    my_revstr(sc);
    sfText_setString(game->ob.text[3].text, sc);
}

void game_loop(game_data *game, obstacle *o)
{
    check_event(game);
    if (game->state == LEVEL_MODE || game->state == INFINITE_MODE) {
        if (game->ob_nb - o->ob_left == 0)
            game->state = WIN;
        move_bg(game, &game->ob);
        move_player(game, &game->ob);
        player_state(&game->ob.player, game);
        move_obstacle(game, o);
        for (int i = o->ob_left; i < game->ob_nb; i++)
            check_collision(&o->o[i], game, game->ob.player.position);
        game->score += 0.1f * game->elapsed;
        score_change(game->score, game);
    }
    game->elapsed = sfTime_asSeconds(sfClock_restart(game->clock));
    update_render(game, o);
}