/*
** EPITECH PROJECT, 2020
** move_player.c
** File description:
** gravity script
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int is_grounded(objects *ob)
{
    if (ob->player.position.y >= 780 && ob->player.state != JUMP) {
        set_poss(&ob->player.position, ob->player.sprite, 100, 780);
        return (1);
    }
    return (0);
}

void move_player(game_data *game, objects *ob)
{
    static float velocity = 0;
    const float gravity = 9.8f;
    const float speed = 5.f;

    velocity += gravity * game->elapsed * speed;
    ob->player.grounded = is_grounded(ob);
    if (!ob->player.grounded && ob->player.state == JUMP &&
        ob->player.current_sprite == 0)
        velocity = -40.f;
    if (ob->player.grounded) {
        ob->player.state = WALK;
        velocity = 0;
    }
    move_poss(&ob->player.position, ob->player.sprite, 0, velocity);
}