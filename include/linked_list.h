/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_elem
{
    char *data;
    struct list_elem *prev;
    struct list_elem *next;
} elem_t;

typedef struct list_s
{
    elem_t *front;
    elem_t *back;
    size_t size;
} list_t;

elem_t *create_new_elem(char *);
void init_list(list_t *);
bool push_front(list_t *, char *);
bool push_back(list_t *, char *);
void pop_front(list_t *);
void pop_back(list_t *);
void print_elem_list(list_t *);
int my_strlen_for_list(list_t *);
void pop_elem(list_t *, elem_t *);
bool push_elem(list_t *, char *, int);
void free_list(list_t *);

#endif
