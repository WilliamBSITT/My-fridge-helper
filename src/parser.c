/*
** EPITECH PROJECT, 2024
** parser
** File description:
** parser
*/

#include "../include/fridge.h"

static int ing_ok(char **tmp, int i, int ok)
{
    if (strcmp(tmp[i], "tomato") != 0 && strcmp(tmp[i], "dough") != 0 &&
        strcmp(tmp[i], "onion") != 0 && strcmp(tmp[i], "pasta") != 0)
        if (strcmp(tmp[i], "olive") != 0 && strcmp(tmp[i], "pepper") != 0 &&
            strcmp(tmp[i], "ham") != 0 && strcmp(tmp[i], "cheese") != 0)
            ok++;
    return ok;
}

static int check_ing_name(char **tmp)
{
    int ok = 0;

    for (int i = 0; tmp[i] != NULL; i = i + 3) {
        ok = ing_ok(tmp, i, ok);
    }
    if (ok != 0)
        return (0);
    return (1);
}

static int check_arg_2(char **tmp)
{
    for (int i = 1; i <= 22; i = i + 3) {
        if (strcmp(tmp[i], "=") != 0)
            return (0);
    }
    return (1);
}

static int check_arg_3(char **tmp)
{
    for (int i = 2; i <= 23; i = i + 3) {
        if (my_str_is_num(tmp[i]) == 0)
            return (0);
    }
    return (1);
}

int parser(fridge_t *f, char *file)
{
    char **tmp = my_stwa(file);
    int true_value = 0;
    int i = 0;

    for (; tmp[i]; i++);
    if ((i != 24) || (!check_ing_name(tmp)) || (!check_arg_2(tmp)) ||
        (!check_arg_3(tmp))) {
        free_word_array(tmp);
        return (0);
    }
    for (int i = 1; tmp[i]; i++) {
        if (my_str_is_num(tmp[i])) {
            f->nb_ing[true_value] = atoi(tmp[i]);
            true_value++;
        }
    }
    free_word_array(tmp);
    return (1);
}
