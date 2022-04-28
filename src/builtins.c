/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** builtins.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

static void not_found(char *path)
{
    my_putstr(path);
    if (access(path, F_OK) == 0) {
        if (access(path, R_OK) == 0) {
            my_putstr(": Not a directory.\n");
        } else {
            my_putstr(": Permission denied.\n");
        }
    } else {
        my_putstr(": No such file or directory.\n");
    }
}

static void my_cd(char **arr, char **env)
{
    char *home = 0;

    if (arr[1] && arr[2]) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    if (arr[1]) {
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

static void my_setenv(char **arr)
{
    if (arr[1] && arr[2] && arr[3]) {
        my_putstr("setenv: Too many arguments.\n");
    } else if (arr[1] && arr[2]) {
        ;
    } else {
        my_putstr("setenv: Not enough arguments.\n");
    }
}

static void my_unsetenv(char **arr)
{
    if (arr[1] && arr[2] && arr[3]) {
        my_putstr("unsetenv: Too many arguments.\n");
    } else if (arr[1] && arr[2]) {
        ;
    } else {
        my_putstr("unsetenv: Not enough arguments.\n");
    }
}

int builtins(char **arr, char **env)
{
    if (my_strcmp(arr[0], "cd") == 0) {
        my_cd(arr, env);
        return 1;
    }
    if (my_strcmp(arr[0], "env") == 0) {
        for (int i = 0; env[i]; i++) {
            my_putstr(env[i]);
            my_putstr("\n");
        }
        return 1;
    }
    if (my_strcmp(arr[0], "setenv") == 0) {
        my_setenv(arr);
        return 1;
    }
    if (my_strcmp(arr[0], "unsetenv") == 0) {
        my_unsetenv(arr);
        return 1;
    }
    return 0;
}
