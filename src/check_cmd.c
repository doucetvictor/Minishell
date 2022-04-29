/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** handle_cmd.c
*/

#include <unistd.h>
#include "my.h"

void handle_cmd(char *path)
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
