/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** main.c
*/

#include "minishell2.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    if (!minishell2(env))
        return 84;
    return 0;
}
