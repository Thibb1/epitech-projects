/*
** EPITECH PROJECT, 2020
** player_move.c
** File description:
** loop for tests
*/

#include "my_rpg.h"

int check_collision(player_s *p, map_s map, int s)
{
    sfVector2f pos_p = p->pos;
    sfVector2i pos = {0, 0};
    if (p->dir == 1)
        pos_p.y -= 7;
    if (p->dir == 2)
        pos_p.y += 7;
    if (p->dir == 3)
        pos_p.x -= 7;
    if (p->dir == 4)
        pos_p.x += 7;
    pos = (sfVector2i){(int) pos_p.x / 64 + 1, (int) pos_p.y / 64};
    pos.y += p->dir == 2;
    pos.x += p->dir == 4;
    if (pos.x < 0 || pos.y <= 0 || pos.x >= map.size_x || pos.y >= map.size_y)
        return (0);
    if (map.arr[pos.y][pos.x].x != 0 || map.arr[pos.y][pos.x].y != 0)
        return (0);
    if ((pos.x < 39 && s != 5) || (s != 0 && s != 3 && s != 5))
        return (0);
    return (1);
}

void player_move(player_s *p)
{
    if (p->dir == 1) {
        p->pos.y -= 8;
        p->rect.top = 0 * 32;
    }
    if (p->dir == 2) {
        p->pos.y += 8;
        p->rect.top = 1 * 32;
    }
    if (p->dir == 3) {
        p->pos.x -= 8;
        p->rect.top = 2 * 32;
    }
    if (p->dir == 4) {
        p->pos.x += 8;
        p->rect.top = 3 * 32;
    }
    sfSprite_setPosition(p->sprite, p->pos);
}

void player_loop_move(my_rpg *rpg, player_s *p)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(p->clock)) > 0.00001 &&
        check_collision(p, rpg->maps[2], rpg->quest.state) && p->dir != 0) {
        player_move(p);
        sfClock_restart(p->clock);
        if (sfTime_asSeconds(sfClock_getElapsedTime(p->clock2)) > 0.1) {
            p->rect.left += 32;
            p->rect.left %= 32 * 3;
            sfClock_restart(p->clock2);
        }
    } else if (p->dir == 0)
        p->rect.left = 0;
    if ((int) p->pos.x % 64 == 0 && (int) p->pos.y % 64 == 0 && p->released)
        p->dir = 0;
    if (p->pos.x / 64 == 38 && rpg->quest.state == 0)
        rpg->quest.state = 1;
    sfSprite_setTextureRect(p->sprite, p->rect);
}

void player_loop_enemy(my_rpg *rpg, player_s *p)
{
    sfVector2i xy = (sfVector2i){(int) p->pos.x / 64 + 1, (int) p->pos.y / 64};
    int do_spawn = RAND_INT(0, 2);

    if (p->released == 0 && rpg->maps[1].arr[xy.y][xy.x].x == 4) {
        if (rpg->maps[1].arr[xy.y][xy.x].y == 1 && do_spawn == 0) {
            rpg->mode = 2;
            rpg->player.released = 1;
            rpg->ui.disp_fight = sfTrue;
        }
    }
}

void player_loop(my_rpg *rpg, player_s *p)
{
    player_loop_move(rpg, p);
    if (rpg->mode != 1)
        sfClock_restart(p->clock3);
    else {
        if (sfTime_asSeconds(sfClock_getElapsedTime(p->clock3)) > 0.5) {
            sfClock_restart(p->clock3);
            player_loop_enemy(rpg, p);
        }
    }
}