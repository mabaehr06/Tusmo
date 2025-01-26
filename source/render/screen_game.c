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

    display_text(string_time, infos.length - 280, 15, sfWhite, 30, 0);
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
        j+=85;
    }
}


void render_time_bar(void)
{
    int i = 0;

    while (i < (int)screen.elapsed_time) {
        display_text("|", infos.length-205, -25 + (infos.height/TIMEOUT)*i, sfRed, 30, 1);
        display_text("|", 197, -25 + (infos.height/TIMEOUT)*i, sfRed, 30, 1);
        i++;
    }
}

void render_current_game_id(void)
{
    sfColor rectangle_color;

    display_rectangle(infos.length-200, 0, 200, infos.height, color.cyan, 1, 3, sfWhite);
    display_text("RESULT", infos.length-160, 25 + screen.scrolling, sfWhite, 30, 0);

    for (int i = 0; i != settings.nb_games; i++) {
        if (i+1 < infos.game_id) {
            if (settings.result_games[i] == 1)
                rectangle_color = color.dark_green;
            if (settings.result_games[i] == 0)
                rectangle_color = color.red;
        }
        if (i+1 == infos.game_id)
            rectangle_color = color.light_gray;
        if (i+1 > infos.game_id) {
            rectangle_color = color.dark_gray;
        }

        display_rectangle(infos.length-150, 75 + 50*i + screen.scrolling, 100, 30, rectangle_color, 1, 2, color.black_cyan);
        if (i+1 > infos.game_id) {
            display_picture("assets/lock.png", infos.length-100, 90 + 50*i + screen.scrolling, 0.1f, 1);

        } else {
            display_text((int_to_str(i+1)), infos.length-140, 77+50*i + screen.scrolling, sfWhite, 20, 1);
        }
    
    }
}

void render_current_word_id(void)
{
    char *str = my_strcat("Word ", int_to_str(infos.game_id));

    display_rectangle(0, 0, 200, infos.height, color.cyan, 1, 3, sfWhite);
    display_text(str, 215, 15, sfWhite, 30, 1);
    free(str);
}

void render_game(void)
{
    screen.elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(screen.clock));
    if (screen.elapsed_time >= TIMEOUT)
        end_application();

    render_current_word_id();
    display_picture("assets/tusmo.png", 100, 100, 0.25f, 1);
    edit_word();
    render_game_time();
    render_all_words();
    render_current_game_id();
    render_time_bar();

    // CHEAT 

    // Display Word
    display_text(words.to_found, infos.length/2, infos.height - 50, sfBlack, 40, 1);
}
