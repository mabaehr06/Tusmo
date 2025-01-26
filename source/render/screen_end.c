/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** end_screen
*/

#include "../../include/project.h"

void render_end_screen(void)
{
    display_text(int_to_str(settings.nb_games), infos.length/2, infos.height/2, sfWhite, 100, 1);
    return;
}
