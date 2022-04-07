/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell1.c
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

int minishell2(char *line, char **env)
{
    if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
        return 0;

    char **arr = my_str_split(line, ' ');

    int pid = fork();
    if (pid) {
        waitpid(pid, 0, 0);
    } else {
        if (line[0] == '/')
            my_exec(arr[0], arr, env);
        else if (line[0] != '\0')
            found_cmd(arr[0], arr, env);
        return 0;
    }

    return 1;
}
