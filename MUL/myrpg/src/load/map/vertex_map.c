/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** loads map struct
*/

#include "my_rpg.h"

void set_coordinates(sfVertex *quad, sfVector2u tex, int pos[2],
    tilemap_s *tiles)
{
    int x = tiles->size.x;
    int y = tiles->size.y;
    int j = pos[0];
    int i = pos[1];
    int a = tex.x;
    int b = tex.y;

    quad[0].position = (sfVector2f){j * 64, i * 64};
    quad[1].position = (sfVector2f){(j + 1) * 64, i * 64};
    quad[2].position = (sfVector2f){(j + 1) * 64, (i + 1) * 64};
    quad[3].position = (sfVector2f){j * 64, (i + 1) * 64};
    quad[0].texCoords = (sfVector2f){a * x, b * y};
    quad[1].texCoords = (sfVector2f){(a + 1) * x, b * y};
    quad[2].texCoords = (sfVector2f){(a + 1) * x, (b + 1) * y};
    quad[3].texCoords = (sfVector2f){a * x, (b + 1) * y};
}

void load_tilemap(map_s *map)
{
    int pos[2];

    for (pos[1] = 0 ; pos[1] < map->size_y ; pos[1]++) {
        for (pos[0] = 0 ; pos[0] < map->size_x; pos[0]++) {
            sfVertex *quad = sfVertexArray_getVertex(map->tile->vertex,
                (pos[0] + pos[1] * map->size_x) * 4);
            set_coordinates(quad, map->arr[pos[1]][pos[0]], pos, map->tile);
        }
    }
}

void destroy_tilemap(tilemap_s *tilemap)
{
    sfVertexArray_destroy(tilemap->vertex);
    sfTexture_destroy(tilemap->texture);
    sfTransformable_destroy(tilemap->transf);
    free(tilemap);
}

void init_tilemap(map_s *map, char *texture_file)
{
    tilemap_s *cur = NULL;
    map->tile = malloc(sizeof(tilemap_s) * 1);
    cur = map->tile;
    cur->vertex = sfVertexArray_create();
    cur->texture = sfTexture_createFromFile(texture_file, NULL);
    cur->size = (sfVector2u) {16, 16};
    cur->transf = sfTransformable_create();
    cur->state.texture = cur->texture;
    cur->state.shader = NULL;
    cur->state.blendMode = sfBlendAlpha;
    cur->state.transform = sfTransformable_getTransform(cur->transf);
    sfVertexArray_setPrimitiveType(cur->vertex, sfQuads);
    sfVertexArray_resize(cur->vertex, map->size_x * map->size_y * 4);
}