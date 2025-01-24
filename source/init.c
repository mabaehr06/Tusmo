/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** init
*/

#include "../include/project.h"

void init_setup_infos(void)
{
    infos.length = 1680;
    infos.height = 850;
    infos.screen = 0;
    infos.win = 0;
    infos.window = sfRenderWindow_create((sfVideoMode){infos.length, infos.height, 32}, "Tusmo", sfResize | sfClose, NULL);
    sfRenderWindow_setPosition(infos.window, (sfVector2i){50, 50});
    infos.font = sfFont_createFromFile("assets/HelveticaNeueBold.otf");
}

void init_setup_malloc_words(void)
{
    words.actual    = malloc(7 * sizeof(char));
    words.to_found  = malloc(7 * sizeof(char));
    words.warray    = malloc(6 * sizeof(char *));
}

void init_setup_fill_words(void)
{
    for (int i = 0; i != 6; i++) {
        words.warray[i] = malloc(7 * sizeof(char));
        for (int j = 0; j < 6; j++) {
            words.warray[i][j] = ' ';
        }
        words.warray[i][6] = '\0';
    }
    words.actual = words.warray[0];
}

void init(void)
{
    init_setup_infos();
    init_setup_malloc_words();
    init_setup_fill_words();
}
