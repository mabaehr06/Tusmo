/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** in_game_event
*/

#include "../../include/project.h"

void right_bar_event(sfEvent event)
{
    if (event.type == sfEvtMouseWheelScrolled) {
            sfVector2i scroll_pos = sfMouse_getPositionRenderWindow(infos.window);
            if (scroll_pos.x >= infos.length-200) {
                if (event.mouseWheel.x%10000 < 0)
                    screen.scrolling += MOUSE_SCROLLING_SENSITIVITY;
                else
                    screen.scrolling -= MOUSE_SCROLLING_SENSITIVITY;
            }
            if (screen.scrolling > 0) {
                screen.scrolling = 0;
            }
            if (screen.scrolling <= - (settings.nb_games+1)*50) {
                screen.scrolling = - (settings.nb_games+1)*50;
            }
            printf("%d\n", screen.scrolling);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.button == sfMouseRight)
                screen.scrolling = 0;
        }
}