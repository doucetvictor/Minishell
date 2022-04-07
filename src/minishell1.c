/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell1.c
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

int minishell1(char *line, char **env)
{
    char **arr = 0;
    int pid = 0;

    if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
        return 0;
    pid = fork();
    if (pid) {
        waitpid(pid, 0, 0);
    } else {
        arr = my_str_split(line, ' ');
        if (line[0] == '/')
            my_exec(arr[0], arr, env);
        else if (line[0] != '\0')
            found_cmd(arr[0], arr, env);
        for (int i = 0; arr[i]; i++) {
            free(arr[i]);
        }
        free(arr);
        return 0;
    }
    return 1;
}
