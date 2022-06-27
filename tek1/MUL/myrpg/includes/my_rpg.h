/*
** EPITECH PROJECT, 2020
** my_rpg.h
** File description:
** includes for my_rpg
*/

#ifndef MY_RPG
    #define MY_RPG

    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "my.h"
    #include "ui.h"

    #define RAND(x, y) ((y) + rand() % ((x) - (y)))
    #define RAND_INT(x, y) ((x) > (y) ? RAND((x) + 1, y) : RAND((y) + 1, x))
typedef struct tilemap_s {
    sfVertexArray *vertex;
    sfTexture *texture;
    sfVector2u size;
    sfRenderStates state;
    sfTransformable *transf;
} tilemap_s;

typedef struct map_s {
    int size_x;
    int size_y;
    sfVector2u **arr;
    tilemap_s *tile;
} map_s;

typedef struct render {
    sfRenderWindow *w;
    sfRenderTexture *t;
    sfSprite *t_sprite;
} render;

typedef struct player_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfView *view;
    sfVector2f pos;
    sfIntRect rect;
    int state;
    int dir;
    int released;
    sfClock *clock;
    sfClock *clock2;
    sfClock *clock3;
} player_s;

typedef struct quest_s {
    sfText *text1;
    sfText *text2;
    sfText *text3;
    sfFont *font;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *textbox;
    int state;
} quest_s;

typedef struct sfx_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite2;
    sfTexture *texture2;
    sfClock *clock;
    sfVector2f pos[20];
    sfVector2f pos2[20];
} sfx_s;

typedef struct my_rpg {
    render r;
    map_s *maps;
    interface_s ui;
    player_s player;
    quest_s quest;
    sfx_s sfx;
    int mode;
} my_rpg;

void load_all(my_rpg *rpg);
void unload_all(my_rpg rpg);
void load_window(render *r);
sfIntRect make_rectangle(int top, int left, int width, int height);
void load_quest_txt2(quest_s *q);
void load_quest_txt(quest_s *q);
void load_quest2(quest_s *q);

int my_fscanf(int file, const char *format, ...);

void start_rpg(void);
void loop(my_rpg *rpg);
void player_loop(my_rpg *rpg, player_s *p);
void draw_particles(sfx_s *sfx, sfRenderTexture *t);

void draw_window(render r, my_rpg *rpg);
void clock_events(my_rpg *rpg);
void analyse_event(my_rpg *rpg, sfEvent event);

void load_map(map_s **maps);
void unload_map(map_s *maps);
void free_map(map_s map);
void print_map(map_s *map);
void get_file_map(char *path, map_s *map);

void set_coordinates(sfVertex *quad, sfVector2u tex, int pos[2],
    tilemap_s *tiles);
void load_tilemap(map_s *map);
void destroy_tilemap(tilemap_s *tilemap);
void init_tilemap(map_s *map, char *texture_file);

void ui_event(my_rpg *rpg, sfEvent event);
void menu_ui_event(my_rpg *rpg, sfEvent event);
void game_ui_event(my_rpg *rpg, sfEvent event);
void sound_menu_click(interface_s *ui);
void check_state(interface_s *ui, sfRenderWindow *window);
void check_soundmenu_state(sfVector2i cursor, s_menu *menu);
void check_specific_button(sfVector2i cursor, button_s *but, sfFloatRect b);

void unload_window(render r);
#endif
