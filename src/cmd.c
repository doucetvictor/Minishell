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

static void not_found(char *cmd)
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

static char** get_path(char **env)
{
    char **args = 0;

    for (int i = 0; env[i]; i++) {
        args = my_str_split(env[i], '=');
        if (my_strcmp(args[0], "PATH") == 0) {
            return my_str_split(args[1], ':');
        }
    }
    return 0;
}

static int my_exec_if_exist(char *cmd, char **arr, char **env)
{
    int fd = open(cmd, O_RDONLY);

    if (fd != -1) {
        close(fd);
        my_exec(cmd, arr, env);
        return 1;
    }
    return 0;
}

void found_cmd(char *arg0, char **arr, char **env)
{
    char **path = get_path(env);
    char *cmd = 0;
    int len = 0;
    int ret = 0;

    for (int i = 0; !ret && path[i]; i++) {
        len = my_strlen(path[i]) + my_strlen(arg0) + 1;
        cmd = malloc(len + 1);
        for (int j = 0; j < len; j++) {
            cmd[j] = '\0';
        }
        my_strcat(cmd, path[i]);
        my_strcat(cmd, "/");
        my_strcat(cmd, arg0);
        ret = my_exec_if_exist(cmd, arr, env);
        free(cmd);
    }
    if (!ret)
        not_found(arg0);
}
