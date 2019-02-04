/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "../include/my.h"

int nb_word(char *str, char sep1)
{
    int words = 0;

    for (int i = 0, var = 0; str[i]; i++) {
        if ((str[i] != sep1 && str[i] != '\t') && var == 0) {
            words += 1;
            var = 1;
        } else if (str[i] == sep1 || str[i] == '\t')
            var = 0;
    }
    return (words);
}

char *create_word(int *let, char *str, char sep1)
{
    int i = 0;
    int j = 0;
    char *word;

    *let = 0;
    for (; str[i] == sep1 || str[i] == '\t'; i++);
    for (; (str[i] != sep1 && str[i] != '\t') && str[i] != 0; i++, *let += 1);
    *let = i;
    word = malloc(sizeof(char) * (*let + 1));
    if (word == NULL)
        return (NULL);
    for (; str[j] == sep1 || str[j] == '\t'; j++);
    for (i = j; (str[i] != sep1 && str[i] != '\t') &&
        str[i] != 0; i++)
        word[i - j] = str[i];
    word[i - j] = 0;
    return (word);
}

char **my_str_to_word_array(char *str, char sep1)
{
    int words = 0;
    char *word = NULL;
    char **word_array = NULL;
    int letters = 0;
    int i = 0;

    if (str == NULL)
        return (NULL);
    words = nb_word(str, sep1);
    word_array = malloc(sizeof(char *) * (words + 1));
    for (i = 0; i < words; i++) {
        word = create_word(&letters, str, sep1);
        str += letters;
        word_array[i] = word;
    }
    word_array[i] = NULL;
    return (word_array);
}
