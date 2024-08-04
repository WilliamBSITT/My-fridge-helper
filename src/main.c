/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/fridge.h"

static char *ingredient_2(char *name_ing)
{
    my_strcat(&name_ing, "onion");
    my_strcat(&name_ing, " ");
    my_strcat(&name_ing, "pasta");
    my_strcat(&name_ing, " ");
    return (name_ing);
}

static int ingredient(fridge_t *f)
{
    char *name_ing = malloc(sizeof(char));

    if (name_ing == NULL)
        return (0);
    name_ing[0] = '\0';
    my_strcat(&name_ing, "tomato");
    my_strcat(&name_ing, " ");
    my_strcat(&name_ing, "dough");
    my_strcat(&name_ing, " ");
    name_ing = ingredient_2(name_ing);
    my_strcat(&name_ing, "olive");
    my_strcat(&name_ing, " ");
    my_strcat(&name_ing, "pepper");
    my_strcat(&name_ing, " ");
    my_strcat(&name_ing, "ham");
    my_strcat(&name_ing, " ");
    my_strcat(&name_ing, "cheese");
    f->ing = my_stwa(name_ing);
    free(name_ing);
    return (1);
}

static int init_struct(fridge_t *f)
{
    char *have_file = NULL;

    f = memset(f, 0, sizeof(fridge_t));
    if (!ingredient(f))
        return (0);
    f->nb_ing = malloc(sizeof(int) * (nb_line(f->ing)));
    if (f->nb_ing == NULL)
        return (0);
    for (int i = 0; i < nb_line(f->ing); i++)
        f->nb_ing[i] = INITIAL_QTY;
    have_file = getline_file(SAVE_FILE);
    if (have_file != NULL) {
        if (!parser(f, have_file)) {
            free(have_file);
            free_all(f);
            return (0);
        }
        free(have_file);
    }
    return (1);
}

static void fridge(fridge_t *f)
{
    while (1) {
        if (getline(&f->buff, &f->len, stdin) == - 1)
            break;
        if (f->buff[0] == '\n')
            continue;
        f->nb_arg = count_words(f->buff);
        f->d_array = my_stwa(f->buff);
        if (arg_handler(f)) {
            free_word_array(f->d_array);
            break;
        }
        free_word_array(f->d_array);
    }
}

void free_all(fridge_t *f)
{
    free(f->nb_ing);
    free_word_array(f->ing);
    free(f->buff);
    free(f);
}

int main(int ac, __attribute__((unused)) const char **av)
{
    fridge_t *f = malloc(sizeof(fridge_t));

    if (f == NULL || ac != 1)
        return (84);
    if (!init_struct(f))
        return (84);
    fridge(f);
    if (!save(f))
        return (84);
    free_all(f);
    return (0);
}
