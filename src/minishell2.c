/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell2.h"
#include "my.h"

static char** init_args(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '\t') {
            line[i] = ' ';
        }
    }
    return my_str_split(line, ' ');
}

static void deinit_args(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}

static int minishell2_exec(char **cmd, char **env, int pids_len)
{
    pid_t *pids = malloc(sizeof(pid_t) * pids_len);
    char **args = 0;
    pid_t pid = 0;
    int oldfd[2];

    for (int i = 0; cmd[i]; i++) {
        args = init_args(cmd[i]);
        pid = minishell1(args, env, oldfd, (int[2]){i == 0, i == pids_len - 1});
        deinit_args(args);
        if (pid != 0) {
            pids[i] = pid;
        } else {
            free(pids);
            return 0;
        }
    }
    for (int i = 0; i < pids_len; i++)
        waitpid(pids[i], 0, 0);
    free(pids);
    return 1;
}

static int minishell2_parse(char *line, char **env)
{
    char **arr = my_str_split(line, ';');
    char **cmd = 0;
    int res = 1;

    for (int i = 0; res && arr[i]; i++) {
        cmd = my_str_split(arr[i], '|');
        res = minishell2_exec(cmd, env, arr_size(cmd));
        deinit_args(cmd);
    }
    deinit_args(arr);
    return res;
}

int minishell2(char **env)
{
    char *line = 0;
    size_t line_len = 0;
    int ret = 1;

    while (ret) {
        my_putstr("$> ");
        if (getline(&line, &line_len, stdin) == -1)
            ret = 0;
        else
            line[my_strlen(line) - 1] = '\0';
        if (ret && !minishell2_parse(line, env))
            ret = 0;
    }
    if (line)
        free(line);
    return ret;
}
