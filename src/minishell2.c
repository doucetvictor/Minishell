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

static int minishell2_exec(char *line, char **env)
{
    char **arr = init_args(line);

    if (!minishell1(arr, env))
        return 0;
    deinit_args(arr);
    return 1;
}

static int minishell2_parse(char *line, char **env)
{
    char **arr = my_str_split(line, ';');

    for (int i = 0; arr[i]; i++) {
        if (!minishell2_exec(arr[i], env)) {
            deinit_args(arr);
            return 0;
        }
    }
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
        if (getline(&line, &line_len, stdin) == -1)
            ret = 0;
        else
            line[my_strlen(line) - 1] = '\0';
        if (ret && !minishell2_parse(line, env))
            ret = 0;
    }
    if (line)
        free(line);
    return ret;
}
