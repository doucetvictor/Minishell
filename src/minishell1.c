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

static void not_found(char *path)
{
    my_putstr(path);
    if (access(path, F_OK) == 0) {
        my_putstr(": Not a directory.\n");
    } else {
        my_putstr(": No such file or directory.\n");
    }
}

static void my_cd(char **arr, char **env)
{
    char *home = 0;

    if (arr[1] && arr[2]) {
        my_putstr("cd: Too many arguments.\n");
    } else if (arr[1]) {
        if (chdir(arr[1]) != 0) {
            not_found(arr[1]);
        }
    } else {
        home = get_home(env);
        if (home) {
            chdir(home);
            free(home);
        } else {
            my_putstr("cd: No home directory.\n");
        }
    }
}

static int builtins(char **arr, char **env)
{
    if (my_strcmp(arr[0], "cd") == 0) {
        my_cd(arr, env);
        return 1;
    }
    return 0;
}

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
