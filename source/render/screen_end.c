/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** end_screen
*/

#include "../../include/project.h"

// 1==Win, -1==Lose
void render_end_screen(void)
{
    if (infos.win == 1) {
        display_text("WIN", 100, 100, sfGreen, 80, 0);
    }
    if (infos.win == -1) {
        display_text("LOSE", 100, 100, sfRed, 80, 0);
    }
    display_text(int_to_str(settings.nb_games), infos.length/2, infos.height/2, sfWhite, 100, 1);
    return;
}
