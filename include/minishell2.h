/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell2.h
*/

#ifndef MINISHELL2_H
    #define MINISHELL2_H

int arr_size(char **arr);

int builtins(char **arr, char **env, char **oldpwd);

void handle_cmd(char *path);

void my_exec(char *cmd, char **arr, char **env);
void found_cmd(char *arg0, char **arr, char **env);

char* get_home(char **env);
char* get_path(char **env);

int minishell1(char **arr, char **env, char **oldpwd, int oldfd[2], int first_last[2]);

int minishell2(char **env);

#endif
