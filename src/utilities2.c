/*
** EPITECH PROJECT, 2024
** epitech
** File description:
** stumper 4
*/

#include "../include/fridge.h"

int my_str_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int count_nb(int nb)
{
    int i = 10;
    int count = 1;

    for (; (nb / i) >= 1; i *= 10)
        count++;
    return (count);
}

char *my_itoa(int nb)
{
    int size = count_nb(nb);
    char *str = malloc(sizeof(char) * size + 1);

    if (str == NULL)
        return (NULL);
    str[size] = '\0';
    for (; size--; nb /= 10)
        str[size] = nb % 10 + '0';
    return (str);
}

char *getline_file(char *filepath)
{
    char *buffer = malloc(sizeof(char));
    char *line = NULL;
    size_t size = 0;
    int byte = 0;
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return (NULL);
    buffer[0] = '\0';
    byte = getline(&line, &size, file);
    while (byte >= 0) {
        my_strcat(&buffer, line);
        byte = getline(&line, &size, file);
    }
    fclose(file);
    free(line);
    return (buffer);
}

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (; i != n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
