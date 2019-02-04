/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** fork and get path
*/

#include "../include/my.h"

int my_fork(char **input, char **env)
{
    int my_fork = fork();
    int stat = 0;

    if (!env)
        return (1);
    if (my_fork == 0) {
        if (execve(input[0], input, env) == -1) {
            my_printf("%s: Exec format error. Binary file not executable.\n",
            input[0]);
            exit(1);
        }
    } else {
        waitpid(my_fork, &stat, 0);
        return (check_signal(stat));
    }
    return (0);
}

char **get_path(list_t *list)
{
    char **path = NULL;
    char *first = NULL;

    first = my_strdup(get_from_env(list, "PATH="));
    if (!first)
        return (NULL);
    path = my_str_to_word_array(first + 5, ':');
    free(first);
    return (path);
}
