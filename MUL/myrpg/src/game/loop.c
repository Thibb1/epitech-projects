/*
** EPITECH PROJECT, 2020
** test_loop.c
** File description:
** loop for tests
*/

#include "my_rpg.h"


void game_loop(my_rpg *rpg, player_s *p)
{
    player_loop(rpg, p);
}

void draw_game_loop(my_rpg *rpg, sfRenderTexture *t, map_s *m)
{
    sfVector2f cam = rpg->player.pos;
    sfRenderTexture_drawVertexArray(t, m[0].tile->vertex, &m[0].tile->state);
    sfRenderTexture_drawVertexArray(t, m[1].tile->vertex, &m[1].tile->state);
    sfRenderTexture_drawVertexArray(t, m[2].tile->vertex, &m[2].tile->state);
    sfRenderTexture_drawSprite(t, rpg->quest.sprite, NULL);
    if (rpg->mode != 0)
        sfRenderTexture_drawSprite(t, rpg->player.sprite, NULL);
    draw_particles(&rpg->sfx, t);
    sfRenderTexture_drawVertexArray(t, m[3].tile->vertex, &m[3].tile->state);
    cam.x += 64;
    cam.x = cam.x < 752 ? 752 : cam.x;
    if (cam.x > (rpg->maps[3].size_x - 12) * 64)
        cam.x = (rpg->maps[3].size_x - 12) * 64;
    cam.y = cam.y < 412 ? 412 : cam.y;
    if (cam.y > (rpg->maps[3].size_y - 6) * 64 - 32)
        cam.y = (rpg->maps[3].size_y - 6) * 64 - 32;
    sfView_setCenter(rpg->player.view, cam);
    sfRenderTexture_setView(rpg->r.t, rpg->player.view);
}

void loop(my_rpg *rpg)
{
    sfEvent ev;

    while (sfRenderWindow_isOpen(rpg->r.w)) {
        check_state(&rpg->ui, rpg->r.w);
        while (sfRenderWindow_pollEvent(rpg->r.w, &ev))
            analyse_event(rpg, ev);
        game_loop(rpg, &rpg->player);
        draw_game_loop(rpg, rpg->r.t, rpg->maps);
        draw_window(rpg->r, rpg);
    }
}
