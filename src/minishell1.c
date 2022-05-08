/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell1.c
*/

#include <unistd.h>
#include "minishell2.h"
#include "my.h"

static void child_exec(char **arr, char **env)
{
    if (arr[0][0] == '/')
        my_exec(arr[0], arr, env);
    else if (arr[0][0] != '\0')
        found_cmd(arr[0], arr, env);
}

static void my_dup2(int *pipefd, int std)
{
    dup2(pipefd[std], std);
    close(pipefd[0]);
    close(pipefd[1]);
}

int minishell1(char **arr, char **env, int oldfd[2], int first, int last)
{
    int pipefd[2];
    int pid = 0;

    if (!arr[0] || builtins(arr, env))
        return 1;
    if (my_strcmp(arr[0], "exit") == 0)
        return 0;
    if (!last && pipe(pipefd) == -1)
        return 0;
    pid = fork();
    if (pid == -1)
        return 0;
    if (pid == 0) {
        if (!first)
            my_dup2(oldfd, 0);
        if (!last)
            my_dup2(pipefd, 1);
        child_exec(arr, env);
    } else {
        if (!first) {
            close(oldfd[0]);
            close(oldfd[1]);
        }
        if (!last) {
            oldfd[0] = pipefd[0];
            oldfd[1] = pipefd[1];
        }
    }
    return pid;
}
