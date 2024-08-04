/*
** EPITECH PROJECT, 2022
** make
** File description:
** make
*/

#include "../../include/fridge.h"

static void remove_used_ing(fridge_t *f)
{
    f->nb_ing[0] -= 5;
    f->nb_ing[1] -= 1;
    f->nb_ing[2] -= 3;
    f->nb_ing[4] -= 8;
    f->nb_ing[5] -= 8;
    f->nb_ing[6] -= 4;
    f->nb_ing[7] -= 3;
}

int make_pizza(fridge_t *f)
{
    if (f->nb_ing[0] < 5)
        return (printf("'make pizza': not enough tomato\n"));
    if (f->nb_ing[1] < 1)
        return (printf("'make pizza': not enough dough\n"));
    if (f->nb_ing[2] < 3)
        return (printf("'make pizza': not enough onion\n"));
    if (f->nb_ing[4] < 8)
        return (printf("'make pizza': not enough olive\n"));
    if (f->nb_ing[5] < 8)
        return (printf("'make pizza': not enough pepper\n"));
    if (f->nb_ing[6] < 4)
        return (printf("'make pizza': not enough ham\n"));
    if (f->nb_ing[7] < 3)
        return (printf("'make pizza': not enough cheese\n"));
    remove_used_ing(f);
    return (0);
}
