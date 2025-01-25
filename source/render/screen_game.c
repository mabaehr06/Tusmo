/*
** EPITECH PROJECT, 2025
** Tusmo
** File description:
** render
*/

#include "../../include/project.h"

char *convert_into_time(char *string, char *type)
{
    char *new_string;

    if (my_strcmp(type, "min")) {
        new_string = malloc(5 * sizeof(char));
        new_string[0] = (convert_str_into_int(string)/60) + '0';
        new_string[1] = ':';
        new_string[2] = (convert_str_into_int(string)%60/10) + '0';
        new_string[3] = (convert_str_into_int(string)%10) + '0';
        new_string[4] = '\0';
        return new_string;
    }
    return string;
}

void render_game_time(void)
{
    char *string_time = int_to_str((int)my_trunc(screen.elapsed_time));

    string_time = convert_into_time(string_time, "min");

    display_text(string_time, 100, 350, sfWhite, 50, 0);
    free(string_time);
}

void render_all_words(void)
{
    int i = 0;
    int midh = infos.height / 2;
    int midl = infos.length / 2;
    int j = -250;
    while (i < 6) {
        show_row(midl - 250, midh + j, words.warray[i]);
        i++;
        j+=100;
    }
}


void render_time_bar(void)
{
    char *progress = malloc(500 * sizeof(char));
    int i = 0;

    while (i < (int)screen.elapsed_time) {
        progress[i] = '-';
        i++;
    }
    progress[i] = '\0';
    display_text(progress, 0, infos.height-40, sfWhite, 40, 0);
    free(progress);
}

void render_current_game_id(void)
{
    sfColor rectangle_color;

    for (int i = 0; i != settings.nb_games; i++) {
        if (i+1 < infos.game_id) {
            if (settings.result_games[i] == 1)
                rectangle_color = sfGreen;
            if (settings.result_games[i] == 0)
                rectangle_color = sfRed;
        }
        if (i+1 == infos.game_id)
            rectangle_color = color.dark_gray;
        if (i+1 > infos.game_id)
            rectangle_color = color.light_gray;

        
        display_rectangle(50 + 100 * i, infos.height - 75, 75, 40, rectangle_color, 1, 5, color.cyan);
        display_text(int_to_str(i+1), 75 + 100 * i, infos.height - 80, sfBlack, 40, 0);
    }
}


void render_game(void)
{
    screen.elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(screen.clock));
    if (screen.elapsed_time >= TIMEOUT)
        end_application();

    display_text(int_to_str(infos.game_id), infos.length/2, 100, sfWhite, 30, 1);
    display_picture("assets/tusmo.png", infos.length/6, 150, 0.5f, 1);
    edit_word();
    render_game_time();
    render_all_words();
    render_current_game_id();
    render_time_bar();

    // CHEAT 
    // display_text(words.to_found, infos.length/2, infos.height - 50, sfBlack, 40, 1);
}
