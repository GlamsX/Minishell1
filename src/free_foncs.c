/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

void free_tabs(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (tab[i] != NULL)
            free(tab[i]);
    free(tab);
}

void free_list(list_t *list)
{
    elem_t *elem = list->front;
    elem_t *tmp;

    while (elem != NULL && list->back != NULL) {
        pop_back(list);
        tmp = elem;
        free(tmp);
        elem = elem->next;
    }
}

void free_all(char **input, char **env, char **path)
{
    if (input)
        free_tabs(input);
    if (env)
        free_tabs(env);
    if (path)
        free_tabs(path);
}
