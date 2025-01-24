/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** all
*/

#include "../../include/project.h"

void render(void)
{
    if (infos.screen == 0)
        render_menu();
    if (infos.screen == 1)
        render_game();
    if (infos.screen == 2)
        render_end_screen();    
}
