/*
** EPITECH PROJECT, 2024
** add_fridge
** File description:
** add_fridge
*/

#include "../../include/fridge.h"

void addtofridge(fridge_t *f, char *ingredient, int const qty)
{
    int i = 0;

    for (; f->ing[i]; i++) {
        if (my_strcmp(f->ing[i], ingredient)) {
            f->nb_ing[i] += qty;
            return;
        }
    }
    printf("'addToFridge %s %d': Invalid operation\n", ingredient, qty);
}
