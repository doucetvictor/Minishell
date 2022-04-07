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

static int minishell2_getline(char **line, size_t *line_len, char **env)
{
    if (getline(line, line_len, stdin) == -1)
        return 0;
    (*line)[my_strlen(*line) - 1] = '\0';
    if (!minishell1(*line, env))
        return 0;
    return 1;
}

int minishell2(char **env)
{
    char *line = 0;
    size_t line_len = 0;
    int ret = 1;

    while (ret) {
        my_putstr("$> ");
        if (!minishell2_getline(&line, &line_len, env))
            ret = 0;
    }
    if (line)
        free(line);
    return ret;
}
