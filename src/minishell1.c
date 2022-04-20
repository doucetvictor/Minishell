/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell1.c
*/

#include <sys/wait.h>
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

int minishell1(char **arr, char **env)
{
    int pid = 0;

    if (!arr[0] || builtins(arr, env))
        return 1;
    if (my_strcmp(arr[0], "exit") == 0)
        return 0;
    pid = fork();
    if (pid) {
        waitpid(pid, 0, 0);
    } else {
        child_exec(arr, env);
        return 0;
    }
    return 1;
}
