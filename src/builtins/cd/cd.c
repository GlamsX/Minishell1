/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** cd
*/

#include "../../../include/my.h"

void change_old_pwd(list_t *list, char *old)
{
    elem_t *elem = list->front;

    for (; elem != NULL && elem->data != NULL; elem = elem->next)
        if (my_strncmp(elem->data, "OLDPWD=", 7) == 0 || !elem || !elem->data)
            break;
    if (!elem || !elem->data) {
        push_back(list, my_strcat("OLDPWD=", old + 4));
        return;
    }
    elem->data = my_strcat("OLDPWD=", old + 4);
}

void change_env(list_t *list)
{
    elem_t *elem = list->front;
    char *old_pwd = get_from_env(list, "PWD=");
    char pwd[4096];

    getcwd(pwd, 4096);
    change_old_pwd(list, old_pwd);
    for (; elem != NULL; elem = elem->next)
        if (my_strncmp(elem->data, "PWD=", 4) == 0)
            break;
    if (!elem || !elem->data)
        return;
    elem->data = my_strcat("PWD=", pwd);
}

int gest_error(char *buf, int ret)
{
    struct stat st;

    if (!buf || ret == 0)
        return (0);
    lstat(buf, &st);
    if (!access(buf, F_OK) && S_ISDIR(st.st_mode)) {
        my_printf("%s: Permission denied.\n", buf);
        return (1);
    } else if (!access(buf, F_OK) && !S_ISDIR(st.st_mode)) {
        my_printf("%s: Not a directory.\n", buf);
        return (1);
    } else {
        if (buf[0] == '-')
            my_printf(": No such file or directory.\n", buf);
        else
            my_printf("%s: No such file or directory.\n", buf);
        return (1);
    }
    return (0);
}

int exec_cd(list_t *list, char **input, char *old_pwd)
{
    char *buf = input[1];
    int ret = 0;

    if (buf && buf[0] == '-') {
        ret = chdir(old_pwd);
        (ret == 0) ? change_env(list) : 0;
    } else if (buf && buf[0] != '-') {
        ret = chdir(buf);
        (ret == 0) ? change_env(list) : 0;
    } else {
        ret = chdir(get_from_env(list, "HOME") + 5);
        (ret == 0) ? change_env(list) : 0;
    }
    return (ret);
}

int my_cd(list_t *list, char **input)
{
    int ret = 0;
    char directory[4096];
    static char *old_pwd = NULL;

    if (strlen_tab(input) > 2) {
        my_printf("cd: Too many arguments.\n");
        return (1);
    }
    (!getcwd(directory, 4096)) ? directory[0] = 0 : 0;
    if (input[1] && (my_strcmp(input[1], "~") == 0 ||
        my_strcmp(input[1], "home") == 0)) {
        (my_strcmp(input[1], "home") == 0) ? my_printf("~ \n") : 0;
        ret = chdir(get_from_env(list, "HOME") + 5);
        (ret == 0) ? change_env(list) : 0;
    } else
        ret = exec_cd(list, input, old_pwd);
    if (directory[0])
        (ret == 0) ? old_pwd = my_strdup(directory) : 0;
    return (gest_error(input[1], ret));
}
