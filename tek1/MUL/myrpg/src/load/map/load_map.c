/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** loads map struct
*/

#include "my_rpg.h"

void print_map(map_s *map)
{
    for (int y = 0; y < map->size_y; y++) {
        for (int x = 0; x < map->size_x; x++)
            my_printf("%d %d|", map->arr[y][x].x, map->arr[y][x].y);
        my_printf("\n");
    }
}

void load_map(map_s **maps)
{
    *maps = malloc(sizeof(map_s) * 4);
    get_file_map("assets/map.txt", &maps[0][0]);
    get_file_map("assets/map_2.txt", &maps[0][1]);
    get_file_map("assets/map_3.txt", &maps[0][2]);
    get_file_map("assets/map_4.txt", &maps[0][3]);
    init_tilemap(&maps[0][0], "assets/game/tile-simple.png");
    init_tilemap(&maps[0][1], "assets/game/tile-simple.png");
    init_tilemap(&maps[0][2], "assets/game/tile-simple.png");
    init_tilemap(&maps[0][3], "assets/game/tile-simple.png");
    load_tilemap(&maps[0][0]);
    load_tilemap(&maps[0][1]);
    load_tilemap(&maps[0][2]);
    load_tilemap(&maps[0][3]);
}

void get_file_map(char *path, map_s *map)
{
    int fd = open(path, O_RDONLY);

    map->size_x = 0;
    map->size_y = 0;
    my_fscanf(fd, "%d%d", &map->size_x, &map->size_y);
    map->arr = malloc(sizeof(sfVector2u *) * map->size_y);
    for (int y = 0; y < map->size_y; y++) {
        map->arr[y] = malloc(sizeof(sfVector2u) * map->size_x);
        for (int x = 0; x < map->size_x; x++)
            my_fscanf(fd, "%d%d", &map->arr[y][x].x, &map->arr[y][x].y);
    }
    close(fd);
}
