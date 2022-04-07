/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** main.c
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

int main(int argc, char **argv, char **env)
{
    char *line;
    size_t line_len;

    while (1) {
        my_putstr("$> ");

        if (getline(&line, &line_len, stdin) == -1)
            return 84;
        line[my_strlen(line) - 1] = '\0';

        int code = minishell2(line, env);
        if (code != 1)
            return code;
    }

    return 0;
}
