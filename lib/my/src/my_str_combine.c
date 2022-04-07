/*
** EPITECH PROJECT, 2022
** my_str_combine.c
** File description:
** my_str_combine
*/

#include <stdlib.h>
#include "my.h"

char* my_str_combine(char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);
    int len = str1_len + str2_len;
    char *out = malloc(len + 1);

    for (int i = 0; i < str1_len; i++) {
        out[i] = str1[i];
    }
    for (int i = 0; i < str2_len; i++) {
        out[str1_len + i] = str2[i];
    }
    out[len] = '\0';
    return out;
}
