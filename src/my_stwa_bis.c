/*
** EPITECH PROJECT, 2024
** my_stwa_bis
** File description:
** my_stwa_bis
*/

#include "../include/fridge.h"

static int alpha_num(char character)
{
    int is_alphanum = 1;

    if (character == '\n' || character == ' ' ||
        character == '\0' || character == '=')
        is_alphanum = 0;
    return (is_alphanum);
}

static int count_words_2(char const *str)
{
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i]) == 1 && alpha_num(str[i + 1]) == 0)
            nb_words++;
    }
    return (nb_words);
}

char **my_stwa_bis(char const *str)
{
    char **word_array = malloc(sizeof(char *) * (count_words_2(str) + 1));
    int nb_words = 0;
    int i_array = 0;

    if (word_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i]) == 1)
            nb_words++;
        if (alpha_num(str[i]) == 1 && alpha_num(str[i + 1]) == 0) {
            word_array[i_array] = malloc(nb_words + 1);
            my_strncpy(word_array[i_array], &str[i - nb_words + 1], nb_words);
            nb_words = 0;
            i_array++;
        }
    }
    word_array[i_array] = NULL;
    return (word_array);
}

void display_array(char const **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }
}

void free_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
