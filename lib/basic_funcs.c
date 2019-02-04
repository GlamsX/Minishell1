/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    if (!dest || !src)
        return (NULL);
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
    char *new = NULL;

    if (!str)
        return (NULL);
    new = malloc(sizeof(char) * my_strlen(str) + 1);
    if (new != NULL) {
        my_strcpy(new, str);
        return (new);
    } else
        return (NULL);
}

int my_strncmp(char *a, char *b, int size)
{
    if (!a || !b)
        return (1);
    for (int i = 0, j = 0; i != size && j != size; i++, j++) {
        if (a[i] != b[j])
            return (1);
        if ((i == size && j != size) || (i != size && j == size))
            return (1);
    }
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}

char *my_strcat(char *str_a, char *str_b)
{
    char *str = NULL;
    int x = 0;
    int y = 0;

    if (str_a == NULL || str_b == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(str_a) + my_strlen(str_b) + 1));
    for (x = 0; x < my_strlen(str_a); x++)
        str[x] = str_a[x];
    for (y = 0; y < my_strlen(str_b); y++) {
        str[x] = str_b[y];
        x++;
    }
    str[x] = '\0';
    return (str);
}
