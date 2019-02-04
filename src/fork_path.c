/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** fork and get path
*/

#include "../include/my.h"

int my_fork(char **input, char **env, int type)
{
    int my_fork = fork();
    int stat = 0;

    if (my_fork == 0) {
        execve(input[0], input, env);
        if (type == 1) {
            free_tabs(input);
            free_tabs(env);
        }
    }
    else {
        waitpid(my_fork, &stat, 0);
        return (stat);
    }
    return (0);
}

char **get_path(list_t *list)
{
    char **path = NULL;
    char *first = my_strdup(get_from_env(list, "PATH="));

    path = my_str_to_word_array(first, ':', '=');
    free(first);
    return (path);
}
