/*
** EPITECH PROJECT, 2025
** Tusmo [WSL: Ubuntu]
** File description:
** parsing_word
*/

#include "../include/project.h"

void word_to_get(void)
{
    FILE *file = fopen("assets/dico", "r");
    char *line = NULL;
    size_t len = 0;
    int cpt = 0;
    int rnb = 0;

    srand(time(NULL));
    rnb = rand()%1951;
    while (getline(&line, &len, file) != -1) {
        cpt++;
        if (rnb == cpt) {
            while (my_strlen(line) != 7)
                getline(&line, &len, file);
            
            words.to_found[0] = line[0];
            words.to_found[1] = line[1];
            words.to_found[2] = line[2];
            words.to_found[3] = line[3];
            words.to_found[4] = line[4];
            words.to_found[5] = line[5];
            words.to_found[6] = '\0';
            free(line);
            break;
        }
    }
    for (int i = 0; words.to_found[i] != '\0'; i++) {
        if (words.to_found[i] >= 'a' && words.to_found[i] <= 'z') {
            words.to_found[i] = words.to_found[i] - 32;
        }
    }
    fclose(file);
    return;
}

void get_int_start_alphabet(void)
{
    int index_letter = 0;

    words.alphabet = malloc(26 * sizeof(int));
    for (int i = 0; i != 26; i++)
        words.alphabet[i] = 0;
    for (int i = 0; words.to_found[i] != '\0'; i++) {
        index_letter = words.to_found[i] - 'A';
        words.alphabet[index_letter]++;
    }
}
