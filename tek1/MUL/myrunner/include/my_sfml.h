/*
** EPITECH PROJECT, 2020
** sfml advanced functions
** File description:
** adds libs for graphical display
*/

#ifndef _MY_SFML_
    #define _MY_SFML_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>

    #define SUCCESS 0
    #define ERROR 84

    #define NAME "Death Runner"

    #define MENU 0
    #define LEVEL_MODE 1
    #define INFINITE_MODE 2
    #define HELP_MODE 3
    #define LOOSE 4
    #define WIN 5

    #define SOUND_NB 2
    #define BG_NB 3
    #define TEXT_NB 7

    #define IDLE 0 // 6 sprites
    #define WALK 1 // 8 sprites
    #define RUN 2 // 6 sprites
    #define JUMP 3 // 3 sprites
    #define FLY 4 // 2 sprites

typedef struct game_window {
    sfMusic *music; // Window main music
    sfVideoMode mode; // Window settings
} game_window;

typedef struct object {
    float current_sprite; // Store current sprite
    unsigned short int state; // Store current state
    unsigned short int grounded; // Say if object touches ground
    sfIntRect rect;
    sfVector2f position; // Current position
    sfTexture *texture; // Object texture
    sfSprite *sprite; // Sprite drawn on screen
    sfMusic *sound[SOUND_NB]; // Sounds events
    sfText *text; // Text data
} object;

typedef struct obstacle {
    object *o;
    int ob_left;
} obstacle;

typedef struct objects {
    object player; // User
    object bg[BG_NB]; // Background sprites
    object text[TEXT_NB]; // Text objects
    sfFont *font; // Text
} objects;

typedef struct game_data {
    unsigned short int state; // Current game state
    float elapsed; // Time since last frame
    float score; // Should store some simple data
    sfEvent ev; // Events are stored in this structure
    sfRenderWindow *render; // Structure to display a window
    sfClock *clock; // Game clock
    objects ob; // Game objets and data
    int ob_nb; // Game obstacles nb
} game_data;

// Game logic
int my_runner(int ac, char *av[]);
void print_help(void);
int load_game(game_data *, game_window *, char *);
int load_calls(game_data *, game_window *, char *, obstacle *);
void unload_game(game_data *, game_window *, obstacle *);


// Game_render
void move_player(game_data *, objects *);
void move_obstacle(game_data *, obstacle *);
void move_bg(game_data *, objects *);
void game_loop(game_data *, obstacle *);
void render_sprite(sfRenderWindow *, objects *, game_data *, obstacle *);
void render_text(sfRenderWindow *, objects, game_data *);
void update_render(game_data *, obstacle *);

// Events
void check_event(game_data *);
void check_key(game_data *, sfKeyEvent);

// Objects
void move_poss(sfVector2f *, sfSprite *, float x, float y);
void set_post(sfText *, float x, float y);
void set_poss(sfVector2f *, sfSprite *, float x, float y);

// >> load
// >>>> AUDIO
int load_audio(objects *);
// >>>> SPRITES
int load_sprites(objects *);
int load_sprite(objects *);
int load_texture(objects *);
int load_clock(game_data *);
// >>>> TEXT
int load_text(objects *);
// >>>> WINDOW
int load_window(game_data *, game_window *);

// >> Unload
// >>>> AUDIO
void unload_audio(objects);
// >>>> SPRITES
void unload_sprites(objects);
void unload_sprite(objects);
void unload_texture(objects);
void unload_clock(game_data *);
// >>>> TEXT
void unload_text(objects);
// >>>> WINDOW
void unload_window(sfRenderWindow *, sfMusic *);

// File and AV
int av_check(int ac, char *av[]);
int av_parse(char *av[]);
int file_check(char *path);
int format_parse(int file, const char c, va_list li);
int my_fscanf(int file, const char *format, ...);
int my_fopen(const char *filepath, const char accesmode);
int my_fclose(int file);
#endif