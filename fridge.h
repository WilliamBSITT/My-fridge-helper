/*
** EPITECH PROJECT, 2024
** Epitech-Fridge--main
** File description:
** fridge
*/

#pragma once
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define SAVE_FILE ".save"
#define INITIAL_QTY 50

typedef struct fridge_s {
    char *buff;
    size_t len;
    char **d_array;
    char **ing;
    int *nb_ing;
    int nb_arg;
} fridge_t;

void free_all(fridge_t *f);
int disp_fridge(fridge_t *f);
int nb_line(char **darray);
void addtofridge(fridge_t *f, char *ingredient, int toadd);
int make_pizza(fridge_t *f);
int make_pasta(fridge_t *f);
int save(fridge_t *f);
int arg_handler(fridge_t *f);
int parser(fridge_t *f, char *file);
char **my_stwa_bis(char const *str);
void free_word_array(char **tab);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
void my_strcat(char **dest, char const *src);
int my_str_is_num(char *str);
int count_nb(int nb);
char *my_itoa(int nb);
char *getline_file(char *filepath);
char *my_strncpy(char *dest, const char *src, int n);
char **my_stwa(char const *str);
int count_words(char const *str);
