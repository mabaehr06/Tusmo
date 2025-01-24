/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** input
*/

#include "../include/project.h"

int is_enough_space(char *string)
{
    if (string[0] == ' ' || string[0] == '.')
        return -2;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ' || string[i] == '.')
            return i-1;
    }
    return -1;
}

void finish_game(char w)
{
    if (w == 'Y') {
        infos.win = 1;
    }
    if (w == 'N') {
        infos.win = -1;
    }
    words.actual = "GAME_ENDED";
    infos.screen = 2;
}

void switch_actual_word(void)
{
    words.actual_id++;

    if (words.actual_id == 6) {
        if (my_strcmp(words.actual, words.to_found))
            finish_game('Y');
        else
            finish_game('N');
        return;
    }
    words.actual = words.warray[words.actual_id];
    return;
}


int remove_letter(void)
{
    int index = is_enough_space(words.actual);

    if (index == -2) {
        return 2;
    }
    if (index == -1) {
        words.actual[my_strlen(words.actual)-1] = ' ';
        return 1;
    }
    words.actual[index] = ' ';
    return 0;
}

int add_letter(char c)
{
    int i = 0;

    while (words.actual[i] != ' ' && words.actual[i] != '.') {
        if (words.actual[i] == '\0') {
            printf("Error message\n");
            // display_error_message("Cannot Content", 100, 100, 3);
            return 1;
        }
        i++;
    }
    words.actual[i] = c;
    return 0;
}

void valid_answer(void)
{
    for (int i = 0; words.actual[i] != '\0'; i++) {
        if (words.actual[i] == ' ' || words.actual[i] == '.')
            return;
    }
    if (my_strcmp(words.actual, words.to_found)) {
        finish_game('Y');
        return;
    }
    switch_actual_word();
}

