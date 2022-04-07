/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** cmd.c
*/

#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"
#include "my.h"

void not_found(char *cmd)
{
    my_putstr("mysh: ");
    my_putstr(cmd);
    if (my_strstr(cmd, "/") || cmd[my_strlen(cmd) - 1] == '/')
        my_putstr(": No such file or directory\n");
    else
        my_putstr(": command not found\n");
}

void my_exec(char *cmd, char **arr, char **env)
{
    int err = execve(cmd, arr, env);
    DIR *dir = opendir(cmd);

    if (dir) {
        closedir(dir);
        my_putstr("mysh: ");
        my_putstr(cmd);
        my_putstr(": Is a directory\n");
    } else {
        not_found(cmd);
    }
}

char** get_path(char **env)
{
    for (int i = 0; env[i]; i++) {
        char **args = my_str_split(env[i], '=');
        if (my_strcmp(args[0], "PATH") == 0) {
            return my_str_split(args[1], ':');
        }
    }
    return 0;
}

void found_cmd(char *arg0, char **arr, char **env)
{
    char **path = get_path(env);
    for (int i = 0; path[i]; i++) {
        int len = my_strlen(path[i]) + my_strlen(arg0) + 1;
        char *cmd = malloc(len + 1);
        cmd[len] = '\0';
        for (int j = 0; cmd[j]; j++) {
            cmd[j] = '\0';
        }
        my_strcat(cmd, path[i]);
        my_strcat(cmd, "/");
        my_strcat(cmd, arg0);

        int fd = open(cmd, O_RDONLY);
        if (fd != -1) {
            close(fd);
            my_exec(cmd, arr, env);
            return;
        }

        free(cmd);
    }
    not_found(arg0);
}
