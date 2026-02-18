/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** in_game_event
*/

// #include "../../include/project.h"

#include "project.h"

void bar_event(sfEvent event)
{
    if (event.type == sfEvtMouseWheelScrolled) {
            sfVector2i scroll_pos = sfMouse_getPositionRenderWindow(infos.window);
            if (scroll_pos.x >= infos.length-200) {
                if (event.mouseWheel.x%10000 < 0)
                    screen.scrolling_r -= MOUSE_SCROLLING_SENSITIVITY;
                else
                    screen.scrolling_r += MOUSE_SCROLLING_SENSITIVITY;
            }
            if (screen.scrolling_r > 0) {
                screen.scrolling_r = 0;
            }
            if (screen.scrolling_r <= - (settings.nb_games+1)*50) {
                screen.scrolling_r = - (settings.nb_games+1)*50;
            }
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.button == sfMouseRight)
                screen.scrolling_r = 0;
        }
}
