/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** builtins.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

static int my_chdir(char *path, char **oldpwd)
{
    char *my_oldpwd = *oldpwd;
    int res = 0;

    *oldpwd = getcwd(0, 0);
    if (my_strcmp(path, "-") == 0) {
        path[0] = '\0';
        res = chdir(my_oldpwd);
    } else {
        res = chdir(path);
    }
    free(my_oldpwd);
    return res;
}

static void my_cd(char **arr, char **env, char **oldpwd)
{
    char *home = 0;

    if (arr[1] && arr[2]) {
        my_putstr("cd: Too many arguments.\n");
        return;
    }
    if (arr[1]) {
        if (my_chdir(arr[1], oldpwd) != 0) {
            handle_cmd(arr[1]);
        }
    } else {
        home = get_home(env);
        if (home) {
            my_chdir(home, oldpwd);
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

int builtins(char **arr, char **env, char **oldpwd)
{
    if (my_strcmp(arr[0], "cd") == 0) {
        my_cd(arr, env, oldpwd);
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
