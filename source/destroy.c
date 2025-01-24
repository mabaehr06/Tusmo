/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** destroy
*/

#include "../include/project.h"

void end_application(void)
{
    write(2, "Window closed, elements destroyed successfully\n", 48);

    sfRenderWindow_close(infos.window);
    // sfRenderWindow_destroy(infos.window);
    // sfClock_destroy(screen.clock);
    sfFont_destroy(infos.font);
    free(words.actual);
    free(words.to_found);
    free(words.alphabet);
}
