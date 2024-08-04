/*
** EPITECH PROJECT, 2024
** save
** File description:
** save
*/

#include "../include/fridge.h"

int saver(char const *data)
{
    int fd = 0;

    fd = open(SAVE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (0);
    write(fd, data, strlen(data));
    close(fd);
    return (1);
}

int save(fridge_t *f)
{
    char *to_write = malloc(sizeof(char));
    char *tmp = NULL;

    if (to_write == NULL)
        return (0);
    to_write[0] = '\0';
    for (int i = 0; f->ing[i]; i++) {
        tmp = my_itoa(f->nb_ing[i]);
        my_strcat(&to_write, f->ing[i]);
        my_strcat(&to_write, " = ");
        my_strcat(&to_write, tmp);
        my_strcat(&to_write, "\n");
        free(tmp);
    }
    if (!saver(to_write)) {
        free(to_write);
        return (0);
    }
    free(to_write);
    return (1);
}
