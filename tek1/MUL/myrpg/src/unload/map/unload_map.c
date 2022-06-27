/*
** EPITECH PROJECT, 2020
** unload_map.c
** File description:
** unloads map struct
*/

#include "my_rpg.h"

void free_map(map_s map)
{
    for (int y = 0; y < map.size_y; y++)
        free(map.arr[y]);
    free(map.arr);
}

void unload_map(map_s *maps)
{
    free_map(maps[0]);
    free_map(maps[1]);
    free_map(maps[2]);
    free_map(maps[3]);
    destroy_tilemap(maps[0].tile);
    destroy_tilemap(maps[1].tile);
    destroy_tilemap(maps[2].tile);
    destroy_tilemap(maps[3].tile);
    free(maps);
}