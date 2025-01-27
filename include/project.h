/*
** EPITECH PROJECT, 2024
** Template_Project
** File description:
** project
*/

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include "../lib/my/my.h"
#include "../lib/myprintf/myprintf.h"
#include "../lib/myutils/myutils.h"
#include "../lib/mymaths/mymaths.h"

#ifndef INCLUDED_PROJECT_H
    #define INCLUDED_PROJECT_H

    #define TIMEOUT 120
    #define MOUSE_SCROLLING_SENSITIVITY 50
    #define NB_GAMES 100; // Max 100


struct infos {
    sfContextSettings *settings;
    sfRenderWindow* window;
    sfFont *font;
    int length;
    int height;
    int screen; // ID (0:MENU, 1:GAME, 2:ENDSCREEN)
    int game_id; // ID of the actual game
};

struct words {
    char ***all_games;
    char **warray;
    char *to_found;
    char *actual;
    int *alphabet;
    int actual_id;
    int *already_found;
};

struct screen {
    float elapsed_time;
    sfClock* clock;
    int scrolling_r;
    int scrolling_l;

};

struct settings {
    int nb_games;
    int *result_games;
};

struct color {
    sfColor black_cyan;
    sfColor dark_cyan;
    sfColor cyan;
    sfColor red;
    sfColor yellow;
    sfColor light_gray;
    sfColor dark_gray;
    sfColor dark_green;
};

extern struct infos infos;
extern struct words words;
extern struct screen screen;
extern struct settings settings;
extern struct color color;

//\\ ----------------------------------

//\\ destroy.c
void end_application(void);

//\\ debug_sf_shape.c
void debug_line_X(int position_x, sfColor color);
void debug_line_Y(int position_x, sfColor color);

//\\ draw_utils.c
void display_text(char *string, int x, int y, sfColor color, int size, int center);
void display_picture(char *path, int x, int y, float scale, int center);
void display_rectangle(int sx, int sy, int tx, int ty, sfColor fill_color, int has_outline, int outline_thickness, sfColor outline_color);
void display_rectangle_corner(sfVector2f position, sfVector2f size, float radius, sfColor color, int is_centered);

//\\ errors.c
int can_error_go(float start_time, float actual_time, int duration);
void display_error_message(char *message, int x, int y, int duration);

//\\ event.c
void carry_event(sfEvent event);
void bar_event(sfEvent event);

//\\ game.c
void relaunch_game(void);

//\\ init.c
void init(void);
void init_setup_malloc_words(void);
void init_setup_fill_words(void);
void init_color(void);

//\\ input.c
int is_enough_space(char *string);
void finish_game(void);
void go_next_word(void);
int remove_letter(void);
int add_letter(char c);
void valid_answer(void);

//\\ parsing_word.c
void word_to_get(void);
void get_int_start_alphabet(void);

//\\ render.c
void render_end_screen(void);
void render_game(void);
void render_menu(void);
void render(void);
void debug_screen(int ac, char **av);

//\\ help_file.c
int help(int ac, char **av);

//\\ csfml_shortcuts.c
sfVector2f sfv2f(int x, int y);
sfVector2i sfv2i(int x, int y);

//\\ word_color.c
int *copy_int_star(int *copy);
sfColor get_color_off(char *string, int index);


//\\ main.c
void show_rectangle(int x, int y, char *string, int index);
void show_row(int x, int y, char *string);
void edit_word(void);

#endif
