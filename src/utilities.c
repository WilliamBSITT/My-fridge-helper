/*
** EPITECH PROJECT, 2024
** utilities
** File description:
** utilities
*/

#include "../include/fridge.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int nb_line(char **data)
{
    int i = 0;

    for (i = 0; data[i]; i++);
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_word1 = my_strlen(s1);
    int len_word2 = my_strlen(s2);

    if (len_word1 != len_word2)
        return (0);
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

void my_strcat(char **dest, char const *src)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(*dest)
    + my_strlen(src) + 1));
    int i = 0;

    for (; (*dest)[i] != '\0'; i++)
        new_str[i] = (*dest)[i];
    for (; src[i - my_strlen(*dest)] != '\0'; i++)
        new_str[i] = src[i - my_strlen(*dest)];
    new_str[i] = '\0';
    free(*dest);
    (*dest) = new_str;
}
