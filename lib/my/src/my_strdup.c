/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    while (src[i++] != '\0')
        ;
    char *dest = malloc(i);
    for (int j = 0; j < i; j++)
        dest[j] = src[j];
    return dest;
}
