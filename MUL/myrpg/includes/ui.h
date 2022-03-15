/*
** EPITECH PROJECT, 2021
** ui.h
** File description:
** ui.h
*/

#ifndef UI
    #define UI
    #include "my_rpg.h"

    #define UI_LIST 3

    #define TEXT_ONLY 1
    #define DECORATED 2

    #define IDLE 3
    #define HOVER 4

typedef struct clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} clock_s;

////////////////
// buttons
////////////////

typedef struct decoration {
    sfRectangleShape *shape;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfColor outline;
} decoration_s;

typedef struct button {
    int type;
    int state;
    decoration_s deco;
    sfText *text;
    sfFont *font;
    sfColor idle;
    sfColor hover;
} button_s;

////////////////
// menu assets
////////////////

typedef struct how_to_play_menu {
    sfRectangleShape *bg;
    sfFont *txt_font;
    sfText *move;
    sfText *op_menu;
    sfText *navigate;
    sfText *skip;
    button_s back;
} htp_menu;

typedef struct menu_ui {
    sfText *title;
    sfFont *title_font;
    button_s play;
    button_s how_to_play;
    button_s quit;
    sfBool disp_htp;
    htp_menu htp;
} menu_ui;

/////////////////
// game ui assets
/////////////////

typedef struct start_menu_background {
    sfRectangleShape *shape;
    sfColor color;
    sfColor outline;
    sfVector2f pos;
    sfVector2f size;
} s_m_bg;

typedef struct sound_menu {
    sfRectangleShape *bg_shape;
    sfColor bg_outline;
    sfFont *font;
    sfText *music;
    sfText *mus_vol;
    button_s minus_music;
    button_s plus_music;
    sfText *effects;
    sfText *eff_vol;
    button_s minus_effects;
    button_s plus_effects;
    button_s back;
} s_menu;

typedef struct game_ui {
    s_m_bg backg;
    button_s sound;
    button_s resume;
    button_s menu;
    button_s quit;
    sfBool dis_s_menu;
    s_menu sound_menu;
} game_ui;

/////////////////////////
// fight screen ui assets
/////////////////////////

typedef struct fight_ui {
    sfMusic *music;
    sfRectangleShape *bg;
    sfText *text;
    button_s back;
} fight_ui;

///////////////////
// interface struct
///////////////////

typedef struct audio {
    sfSoundBuffer *click_sbuf;
    sfSound *click;
    sfMusic *menu_sic;
    sfMusic *game_sic;
    char *mus_vol;
    char *s_vol;
    int music_volume;
    int sound_volume;
} audio_s;

typedef struct interface {
    menu_ui menu;
    sfBool disp_menu;
    game_ui game;
    sfBool disp_game;
    fight_ui fight;
    sfBool disp_fight;
    audio_s audio;
} interface_s;

void load_interface(interface_s *ui);

// Menu interface loading
void load_menu_interface(menu_ui *menu);
void set_how_to_play_button(button_s *button);
void set_quit_button(button_s *button);
void set_play_button(button_s *button);
void set_htp_texts(htp_menu *menu);
void set_htp_background(htp_menu *menu);
void set_htp_back_button(button_s *button);

// Game interface loading
void load_game_interface(game_ui *game);
void load_game_quit(button_s *button);
void load_game_resume(button_s *button);
void load_game_menu(button_s *button);
void load_game_sound(button_s *button);
void load_sound_menu(s_menu *menu);
void load_minus_music(button_s *button);
void load_plus_music(button_s *button);
void load_minus_effects(button_s *button);
void load_plus_effects(button_s *button);
void load_back_button(button_s *button);

// Fight interface loading
void load_fight_interface(fight_ui *fight);

// Drawing ui
void draw_ui(sfRenderWindow *win, interface_s ui);

// Destoying interface
void unload_ui(interface_s ui);

#endif
