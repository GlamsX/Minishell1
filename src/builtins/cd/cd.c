/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** cd
*/

#include "../../../include/my.h"

int gest_error(char *buf, int ret)
{
    struct stat st;

    if (!buf || ret == 0)
        return (0);
    lstat(buf, &st);
    if (!access(buf, F_OK) && !S_ISDIR(st.st_mode)) {
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

int my_cd(list_t *list, char **input)
{
    char *buf = input[1];
    int ret = 0;
    char cwd[4096];
    static char *local = NULL;

    if (!getcwd(cwd, 4096))
        cwd[0] = 0;
    if (buf && buf[0] == '-')
        ret = chdir(local);
    else if (buf && buf[0] != '-')
        ret = chdir(buf);
    else
        ret = chdir(get_from_env(list, "HOME") + 5);
    if (cwd[0])
        local = my_strdup(cwd);
    return (gest_error(buf, ret));
}
