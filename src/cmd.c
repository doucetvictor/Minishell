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
    my_putstr(cmd);
    my_putstr(": Command not found.\n");
}

void my_exec(char *cmd, char **arr, char **env)
{
    DIR *dir = 0;

    execve(cmd, arr, env);
    dir = opendir(cmd);
    if (dir) {
        closedir(dir);
        handle_cmd(cmd);
    } else {
        not_found(cmd);
    }
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
    char **path = my_str_split(get_path(env), ':');
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
