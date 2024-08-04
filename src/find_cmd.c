/*
** EPITECH PROJECT, 2024
** find_cmd
** File description:
** find_cmd
*/

#include "../include/fridge.h"

static void do_kitchen(fridge_t *f)
{
    if (my_strcmp(f->d_array[1], "pizza"))
        make_pizza(f);
    else if (my_strcmp(f->d_array[1], "pasta"))
        make_pasta(f);
    else {
        printf("'%s': meal unknown\n", f->d_array[1]);
    }
}

int arg_handler(fridge_t *f)
{
    if (f->nb_arg == 2 && my_strcmp(f->d_array[0], "disp") &&
        my_strcmp(f->d_array[1], "fridge")) {
        return (disp_fridge(f));
    }
    if (f->nb_arg == 3 && my_strcmp(f->d_array[0], "addToFridge") &&
        my_str_is_num(f->d_array[2])) {
        addtofridge(f, f->d_array[1], atoi(f->d_array[2]));
        return (0);
    }
    if (f->nb_arg == 2 && my_strcmp(f->d_array[0], "make")) {
        do_kitchen(f);
        return (0);
    }
    if (f->nb_arg == 1 && my_strcmp(f->d_array[0], "exit"))
        return (1);
    printf("'");
    for (int i = 0; i < my_strlen(f->buff) - 1; i++)
        printf("%c", f->buff[i]);
    printf("': Invalid operation\n");
    return (0);
}
