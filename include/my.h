/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/wait.h>
#include "get_next_line.h"
#include "my_printf.h"
#include "linked_list.h"

typedef struct pointeur_s
{
    char *name;
    int (*pointeur)(list_t *, char **);
} pointeur_t;

typedef struct echo_s
{
    char *name;
    int (*type)(list_t *, char **);
} echo_t;

int my_strcmp(char *, char *);
int do_setenv(list_t *, char **);
int do_setenv_2(list_t *, char *, char *);
char *get_from_env(list_t *, char *);
char **get_path(list_t *);
int my_fork(char **, char **, int);
int my_exit(list_t *, char **);
int my_unsetenv(list_t *, char **);
int my_setenv(list_t *, char **);
int my_env(list_t *, char **);
int my_cd(list_t *, char **);
char *my_strdup(char *);
char *my_strcat(char *, char *);
char **my_str_to_word_array(char *, char, char);
char **get_new_env(list_t *);
int execution(char *, list_t *, int);
int my_strncmp(char *, char *, int);
void my_put(int, char *);
void free_tabs(char **);
void free_all(char **, char **, char **);
void stock_env(list_t *, char **);

#endif /* MY_H */
