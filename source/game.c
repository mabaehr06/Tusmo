/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** game
*/

#include "../include/project.h"

void go_next_word(void)
{
    words.actual_id++;

    if (words.actual_id == 6) {
        finish_game();
        return;
    }
    words.actual = words.warray[words.actual_id];
    return;
}

void relaunch_game(void)
{
    infos.screen = 1;
    words.actual_id = 0;
    sfClock_restart(screen.clock);
    init_setup_malloc_words();
    init_setup_fill_words();
    word_to_get();
}

void finish_game(void)
{
    if (my_strcmp(words.actual, words.to_found))
        settings.result_games[infos.game_id-1] = 1;
    else
        settings.result_games[infos.game_id-1] = 0;

    if (infos.game_id == settings.nb_games) {
        infos.screen = 2;
        return;
    }
    infos.game_id++;
    relaunch_game();
    return;
}