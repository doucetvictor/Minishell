/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell1.h
*/

#ifndef MINISHELL2_H
    #define MINISHELL2_H

void my_exec(char *cmd, char **arr, char **env);
void found_cmd(char *arg0, char **arr, char **env);

int minishell2(char *line, char **env);

#endif
