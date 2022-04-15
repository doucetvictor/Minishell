/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell2.h"
#include "my.h"

static char** init_args(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '\t') {
            line[i] = ' ';
        }
    }
    return my_str_split(line, ' ');
}

static void deinit_args(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}

static int minishell2_getline(char **line, size_t *line_len)
{
    if (getline(line, line_len, stdin) == -1)
        return 0;
    (*line)[my_strlen(*line) - 1] = '\0';
    return 1;
}

static int minishell2_exec(char *line, char **env)
{
    char **arr = init_args(line);

    if (!minishell1(arr, env))
        return 0;
    deinit_args(arr);
    return 1;
}

int minishell2(char **env)
{
    char *line = 0;
    size_t line_len = 0;
    int ret = 1;

    while (ret) {
        my_putstr("$> ");
        if (!minishell2_getline(&line, &line_len))
            ret = 0;
        else if (!minishell2_exec(line, env))
            ret = 0;
    }
    if (line)
        free(line);
    return ret;
}
