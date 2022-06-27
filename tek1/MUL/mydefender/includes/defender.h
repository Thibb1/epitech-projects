/*
** EPITECH PROJECT, 2020
** binary.h
** File description:
** includes for binary binary
*/

#ifndef DEFENDER
    #define DEFENDER
    #include <stdio.h>

    #define NB_LVL 1

    #define NB_SCENE 3

    #define MENU 0
    #define LVL 1
    #define PAUSE 2

    #define START_GOLD 150

    #define B_IDLE 0
    #define B_HOVER 1
    #define B_CLICKED 2
    #define B_DISABLE 3

    #define E_CIRCLE 1
    #define E_TRIANGLE 3
    #define E_SQUARE 4
    #define E_OCTAGON 8

    #define T_CIRCLE 1
    #define T_TRIANGLE 3
    #define T_SQUARE 4
    #define T_OCTAGON 8

    #define M_ABS(x) (((x) < 0) ? ((x) * - 1) : (x))

    #include "my.h"
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>

////////////////////////////////////////////////////////////
/// \brief text contains every attribute of a text box
///
////////////////////////////////////////////////////////////
typedef struct text {
    sfText *text;
    sfVector2f pos;
    sfColor color;
} text;

void init_text(text *text, sfColor color, sfVector2f pos_fs[2], char *str);

////////////////////////////////////////////////////////////
/// \brief button contains every attribute of a button
///
////////////////////////////////////////////////////////////
typedef struct button {
    int state;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfTexture *texture;
    sfColor color;
    sfColor outline;
} button;

void init_button(button *button, sfColor colors[2], sfVector2f pos_size[2],
    char *texture);
void is_hover(sfMouseMoveEvent click, button *b);
void is_clicked(sfMouseButtonEvent click, button *b);

////////////////////////////////////////////////////////////
/// \brief toggles defines toggles to turn on or off some settings
///
////////////////////////////////////////////////////////////
typedef struct toggles {
    int music;
    int sounds;
} toggles;

typedef struct shop {
    sfRectangleShape *outline;
    button *but;
    text *text;
    sfCircleShape *shapes[8];
    int nb_but;
    int nb_text;
} shop;

typedef struct duck {
    sfSprite *sprite_duck;
    sfTexture *texture_duck;
    sfVector2f position;
    sfIntRect rect;
    int duck_state;
} duck;

typedef struct sound {
    sfSound *sound;
    sfSoundBuffer * sound_buffer;
} sound;

typedef struct scene {
    button *but;
    text *text;
    int nb_but;
    int nb_text;
    shop *sh;
    duck *daffyduck;
    sound s;
} scene;

typedef struct window {
    int state;
    int scene;
    int fps;
    int launched;
    sfEvent ev;
    sfVideoMode vm;
    sfRenderWindow *rw;
    toggles tg;
    sfColor bg;
    scene *scenes;
} window;

typedef struct game_score {
    int t_coins;
    int t_enemies;
    int t_waves;
    int t_towers;
    int t_time;
    int b_score;
} game_score;

typedef struct game {
    sfRectangleShape **rect;
    int nb_cases;
    int nb_enemies;
    int nb_tower;
} game;

typedef struct enemy {
    int phase;
    float life;
    int type;
    sfVector2f pos;
    sfCircleShape *shape;
    sfRectangleShape *lifebar;
    struct enemy *next;
} enemy;

enemy *head_enemy(int type, sfColor c);
void create_enemy(enemy *head, int type, sfColor c);

typedef struct tower {
    int level;
    int type;
    int state;
    double range;
    sfVector2f pos;
    sfCircleShape *shape;
    sfCircleShape *outshape;
    sfCircleShape *radius;
    struct tower *next;
} tower;

typedef struct popup {
    sfClock *clock;
    float t;
    int scene;
    sfText *text;
    struct popup *next;
} popup;

typedef struct assets {
    game_score gs;
    int current_s;
    int coins;
    int lives;
    sfClock *s;
    sfClock *timer;
    scene *scenes;
    sfColor disable;
    sfColor hover;
    sfColor primary;
    sfColor accent;
    game lvl;
    enemy *head;
    tower *t_head;
    popup *pop;
    sfFont *font;
} assets;

void nb_to_str(char str[1048], int nb);

int my_defender(void);

void main_loop(window *win, assets *as);
void game_loop(assets *as);
void check_tower(assets *as);

void popup_show(window *win, assets *as);
void create_popup(assets *as, char *str, float f[3], int set[3]);

void create_tower(assets *as, int type, sfColor c, sfVector2f pos);
void set_tower(tower *cur, sfColor c, sfVector2f pos, int type);
sfVector2f get_tower_placement(sfMouseButtonEvent c);
sfVector2f get_tower_placement_move(sfMouseMoveEvent c);
void color_tow(window *win, shop sh, tower *tow);
void check_click_tower(sfMouseButtonEvent click, shop sh);
int check_tower_button(shop sh, tower *cur, assets *as);
void hover_tower_button(sfMouseMoveEvent click, shop sh, tower *c);
void remove_tower(assets *as, int n);

void set_phase(enemy *current);
void set_move(enemy *current, float deltatime);
void enemy_move(assets *as, float deltatime);
void check_head(assets *as);
void enemy_coins(assets *as, enemy *cur);
void enemy_to_base(assets *as);

assets load_game(window *win);
void load_settings(window *win);
void load_score(assets *as);
void load_assets(assets *as);
void load_lvl(game *lvl);

void save_and_close(window *win, assets *as);
void unload_game(window *win, assets *as);
void remove_lists(assets *as);
void remove_pops(assets *as);

void get_userinput(window *win, assets *as);
void get_key(window *win, sfKeyEvent key);
void click_lvl(sfMouseButtonEvent click, window *win, shop *sh, assets *as);
void check_lvl(shop *sh);
void click_tower(window *win, sfMouseButtonEvent click, assets *as);
void check_hover(sfMouseMoveEvent click, assets *as);

int my_fscanf(int file, const char *format, ...);
void create_file(char *filename);
void check_click(window *win, sfMouseButtonEvent click, assets *as);
void load_inspector(shop *sh);
void load_sell_but(shop *sh);

void place_tower(int type, sfMouseButtonEvent click, assets *as);

void reset_game(window *win, assets *as);

void create_duck(duck *daffyduck);

void init_quit_sounds(sound *s);

#endif
