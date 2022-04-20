/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** env.c
*/

#include <stdlib.h>
#include "my.h"

static char* get_var(char **env, char *key)
{
    char **args = 0;
    char *var = 0;

    for (int i = 0; env[i] && !var; i++) {
        args = my_str_split(env[i], '=');
        if (my_strcmp(args[0], key) == 0)
            var = my_strdup(args[1]);
        for (int j = 0; args[j]; j++)
            free(args[j]);
        free(args);
    }
    return var;
}

char* get_home(char **env)
{
    return get_var(env, "HOME");
}
