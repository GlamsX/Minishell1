/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

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

int exec_with_path(list_t *list, char **input, char **env, int type)
{
    char **path = get_path(list);
    char *save = input[0];
    char *a = NULL;
    int ret_value = find_builtin(list, input);

    if (ret_value == 0)
        return (0);
    if (ret_value == 1)
        return (1);
    a = my_strcat("/", input[0]);
    for (int i = 0; path[i] != NULL; i++) {
        input[0] = my_strcat(path[i], a);
        if (access(input[0], F_OK) == 0) {
            free(a);
            return (my_fork(input, env, type));
        }
    }
    if (access(input[0], F_OK) != 0 && ret_value == -1)
        my_printf("%s: Command not found.\n", save);
    return (1);
}

int execution(char *str, list_t *list, int type)
{
    char **input = NULL;
    char **env = get_new_env(list);

    if (!str)
        return (0);
    input = my_str_to_word_array(str, 0, 0);
    if (input[0] != 0) {
        if (access(input[0], F_OK) == 0)
            return (my_fork(input, env, type));
        if (access(input[0], F_OK) != 0)
            return (exec_with_path(list, input, env, type));
    }
    return (0);
}
