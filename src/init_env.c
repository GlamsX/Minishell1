/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

void stock_env(list_t *list, char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        push_back(list, env[i]);
}

char **get_new_env(list_t *list)
{
    char **tab = malloc(sizeof(char *) * (my_strlen_for_list(list) + 1));
    elem_t *elem = list->front;
    int i = 0;

    for (; elem; elem = elem->next, i++)
        tab[i] = elem->data;
    tab[i] = NULL;
    return (tab);
}

char *get_from_env(list_t *list, char *to_get)
{
    elem_t *elem = list->front;

    while (elem) {
        if (my_strncmp(elem->data, to_get, my_strlen(to_get)) == 0)
            return (elem->data);
        elem = elem->next;
    }
    return (NULL);
}
