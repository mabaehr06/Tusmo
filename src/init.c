/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** init
*/

#include "../include/project.h"

void init_setup_infos(void)
{
    infos.length = 1500;
    infos.height = (float)(infos.length * (float)(9.0f/16.0f));
    infos.screen = 0;
    infos.game_id = 1;
    screen.scrolling_r = 0;
    screen.scrolling_l = 0;

    infos.window = sfRenderWindow_create((sfVideoMode){infos.length, infos.height, 32}, "Tusmo", sfResize | sfClose, NULL);
    sfRenderWindow_setPosition(infos.window, (sfVector2i){50, 50});
    infos.font = sfFont_createFromFile("assets/HelveticaNeueBold.otf");


    settings.nb_games = NB_GAMES;

    words.all_games = malloc(settings.nb_games * sizeof(char **));

    for (int i = 0; i != settings.nb_games; i++) {
        words.all_games[i] = malloc(6* sizeof(char *));
        for (int j = 0; j != 6; j++) {
            words.all_games[i][j] = malloc(7 * sizeof(char));
            for (int k = 0; k != 6; k++) {
                words.all_games[i][j][k] = ' ';
            }
            words.all_games[i][j][6] = '\0';
        }
    }


    settings.result_games = malloc(settings.nb_games * sizeof(int));
    for (int i = 0; i != settings.nb_games; i++) {
        settings.result_games[i] = 84;
    }
}

void init_setup_malloc_words(void)
{
    words.actual        = malloc(7 * sizeof(char));
    words.to_found      = malloc(7 * sizeof(char));
    words.warray        = malloc(6 * sizeof(char *));
    words.already_found = malloc(6 * sizeof(int));

    for (int i = 0; i != 6; i++) {
        words.already_found[i] = 0;
    }
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

void init_color(void)
{
    color.red = sfColor_fromRGB(219, 58, 52);
    color.yellow = sfColor_fromRGB(220, 183, 53);
    color.cyan = sfColor_fromRGB(23, 126, 137);
    color.black_cyan = sfColor_fromRGB(8, 76, 97);
    color.dark_cyan = sfColor_fromRGB(7, 66, 84);
    color.light_gray = sfColor_fromRGB(145, 145, 145);
    color.dark_gray = sfColor_fromRGB(70, 70, 70);
    color.dark_green = sfColor_fromRGB(29, 125, 0);
}

void init(void)
{
    init_setup_infos();
    init_setup_malloc_words();
    init_setup_fill_words();
    init_color();
}
