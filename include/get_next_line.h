/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#ifndef READ_SIZE

#define READ_SIZE (1)

#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_next_line(int);
