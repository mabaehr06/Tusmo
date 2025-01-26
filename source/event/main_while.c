/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** event
*/

#include "../../include/project.h"

void event_main_game(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyBackspace)
            remove_letter();
        else if (event.key.code == sfKeyEnter)
            valid_answer();
        else {
            if (event.key.code >= sfKeyA && event.key.code <= sfKeyZ) {
                add_letter('A' + (event.key.code - sfKeyA));
            }
        }
    }
    right_bar_event(event);
}

void event_menu(sfEvent event)
{
    sfVector2i pos;
    int startx = 0;
    int starty = 0;
    int endx = 0;
    int endy = 0;


    if (event.type == sfEvtMouseButtonPressed) {
        pos = sfMouse_getPositionRenderWindow(infos.window);
        startx  = infos.length/2 - 524/2;
        starty  = infos.height/2 - 103/2;
        endx    = infos.length/2 + 524/2;
        endy    = infos.height/2 + 103/2;

        if (pos.x >= startx && pos.x <= endx && pos.y >= starty && pos.y <= endy) {
            screen.clock = sfClock_create();
            infos.screen = 1;
        }
    }
}

void event_end_screen(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEnter) {
            end_application();
        }
    }
}


void carry_event(sfEvent event)
{
    while (sfRenderWindow_pollEvent(infos.window, &event)) {
        if (infos.screen == 0) {
            event_menu(event);
            continue;
        }
        if (infos.screen == 1) {
            event_main_game(event);
            continue;
        }
        if (infos.screen == 2) {
            event_end_screen(event);
            continue;
        }
    }
}