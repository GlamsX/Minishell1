/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"
#include <stdbool.h>

static const pointeur_t pointeur_g[] = {
    {"setenv", &my_setenv},
    {"env", &my_env},
    {"exit", &my_exit},
    {"cd", &my_cd},
    {"unsetenv", &my_unsetenv},
    {NULL, NULL}
};

int find_builtin(list_t *list, char **inp)
{
    if (!inp)
        return (84);
    for (int x = 0; pointeur_g[x].name != NULL; x++) {
        if (!inp[0])
            return (84);
        if (my_strcmp(inp[0], pointeur_g[x].name) == 0) {
            return (pointeur_g[x].pointeur(list, inp));
        }
    }
    return (-1);
}

int exec_check(char **input, char **env, list_t *list)
{
    char **path = get_path(list);
    char *a = NULL;

    a = my_strcat("/", input[0]);
    for (int i = 0; path && path[i] != NULL; i++) {
        input[0] = my_strcat(path[i], a);
        if (access(input[0], X_OK) == 0) {
            free(a);
            return (my_fork(input, env));
        }
    }
    return (1);
}

int exec_with_path(list_t *list, char **input, char **env)
{
    char *save = input[0];
    int ret_value = find_builtin(list, input);
    int exec_fork = 0;

    if (ret_value == 0 || ret_value == 1)
        return (ret_value);
    exec_fork = exec_check(input, env, list);
    if (exec_fork != 1)
        return (exec_fork);
    if (access(input[0], X_OK) != 0 && ret_value == -1)
        my_printf("%s: Command not found.\n", save);
    return (1);
}

int check_if_fold(char *input)
{
    struct stat st;

    lstat(input, &st);
    if (!access(input, X_OK) && S_ISDIR(st.st_mode)) {
        my_printf("%s: Permission denied\n", input);
        return (1);
    } else
        return (0);
}

int execution(char *str, list_t *list)
{
    char **input = NULL;
    char **env = get_new_env(list);

    if (!str)
        return (0);
    input = my_str_to_word_array(str, ' ');
    if (input[0] == 0)
        return (0);
    if (check_if_fold(input[0]) != 0)
        return (1);
    if (access(input[0], X_OK) == 0)
        return (my_fork(input, env));
    if (access(input[0], X_OK) != 0)
        return (exec_with_path(list, input, env));
    return (0);
}
