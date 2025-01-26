/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** word_color
*/

#include "../../include/project.h"

int *copy_int_star(int *copy)
{
    int *new_int = malloc(26 * sizeof(int));

    for (int i = 0; i != 26; i++)
        new_int[i] = copy[i];
    return new_int;
}

sfColor get_color_off(char *string, int index)
{
    int remaining_letters[26] = {0};
    int used_positions[6] = {0};
    char letter = ' ';
    char current_letter = ' ';

    if (string == words.actual)
        return sfColor_fromRGB(23, 126, 137);
    if (string[0] == ' ')
        return sfColor_fromRGB(8, 76, 97);
    if (string[index] == words.to_found[index])
        return sfColor_fromRGB(219, 58, 52);
    for (int i = 0; i < 6; i++) {
        letter = words.to_found[i];
        remaining_letters[letter - 'A']++;
    }
    for (int i = 0; i < 6; i++) {
        if (string[i] == words.to_found[i]) {
            remaining_letters[string[i] - 'A']--;
            used_positions[i] = 1;
        }
    }
    current_letter = string[index];
    if (remaining_letters[current_letter - 'A'] > 0) {
        for (int i = 0; i < 6; i++) {
            if (!used_positions[i] && words.to_found[i] == current_letter) {
                used_positions[i] = 1;
                remaining_letters[current_letter - 'A']--;
                return sfColor_fromRGB(220, 183, 53);
            }
        }
    }
    return sfColor_fromRGB(8, 76, 97);
}
