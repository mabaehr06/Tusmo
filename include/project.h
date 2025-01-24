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



struct infos {
    sfRenderWindow* window;
    sfFont *font;
    int length;
    int height;
    int screen; // ID (0:MENU, 1:GAME, 2:ENDSCREEN)
    int win;
};

struct words {
    char **warray;
    char *to_found;
    char *actual;
    int *alphabet;
    int actual_id;
};

struct screen {
    float elapsed_time;
    sfClock* clock;
};

extern struct infos infos;
extern struct words words;
extern struct screen screen;

//\\ ----------------------------------

//\\ destroy.c
void end_application(void);

//\\ draw_utils.c
void display_text(char *string, int x, int y, sfColor color, int size, int center);
void display_picture(char *path, int x, int y, float scale, int center);

//\\ errors.c
int can_error_go(float start_time, float actual_time, int duration);
void display_error_message(char *message, int x, int y, int duration);

//\\ event.c
void carry_event(sfEvent event);

//\\ game.c
void relaunch_game(void);

//\\ init.c
void init(void);
void init_setup_malloc_words(void);
void init_setup_fill_words(void);

//\\ input.c
int is_enough_space(char *string);
void finish_game(char w);
void switch_actual_word(void);
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

//\\ word_color.c
int *copy_int_star(int *copy);
sfColor get_color_off(char *string, int index);


//\\ main.c
void show_rectangle(int x, int y, char *string, int index);
void show_row(int x, int y, char *string);
void edit_word(void);


#endif
