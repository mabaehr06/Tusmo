/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** screen_menu
*/

#include "../../include/project.h"

void render_menu(void)
{
    display_picture("assets/tusmo.png", infos.length/2, infos.height/6, 0.5f, 1);
    display_picture("assets/menu_button.png", infos.length/2, infos.height/2, 1.0f, 1);
}

