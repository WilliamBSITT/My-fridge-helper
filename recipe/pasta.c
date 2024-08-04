/*
** EPITECH PROJECT, 2022
** pasta
** File description:
** pasta
*/

#include "../../include/fridge.h"

int make_pasta(fridge_t *f)
{
    if (f->nb_ing[0] < 5)
        return printf("'make pasta': not enough tomato\n");
    if (f->nb_ing[3] < 2)
        return printf("'make pasta': not enough pasta\n");
    if (f->nb_ing[4] < 6)
        return printf("'make pasta': not enough olive\n");
    if (f->nb_ing[6] < 4)
        return printf("'make pasta': not enough ham\n");
    if (f->nb_ing[7] < 3)
        return printf("'make pasta': not enough cheese\n");
    f->nb_ing[0] -= 5;
    f->nb_ing[3] -= 2;
    f->nb_ing[4] -= 6;
    f->nb_ing[6] -= 4;
    f->nb_ing[7] -= 3;
    return (0);
}
