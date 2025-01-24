/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** game
*/

#include "../include/project.h"

void relaunch_game(void)
{
    infos.screen = 1;
    infos.win = 0;
    words.actual_id = 0;
    sfClock_restart(screen.clock);
    init_setup_malloc_words();
    init_setup_fill_words();
    word_to_get();
}