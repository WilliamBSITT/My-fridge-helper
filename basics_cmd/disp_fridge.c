/*
** EPITECH PROJECT, 2024
** disp_fridge
** File description:
** disp_fridge
*/

#include "../../include/fridge.h"

int disp_fridge(fridge_t *f)
{
    for (int i = 0; f->ing[i]; i++) {
        printf("%s = %i\n", f->ing[i], f->nb_ing[i]);
    }
    return (0);
}
