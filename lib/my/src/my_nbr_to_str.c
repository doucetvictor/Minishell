/*
** EPITECH PROJECT, 2021
** my_nbr_to_str.c
** File description:
** my_nbr_to_str
*/

#include <stdlib.h>
#include "my.h"

char* my_nbr_to_str(int nb)
{
    char *str = malloc(12);
    int i = 0;
    if (nb < 0) {
        str[i++] = '-';
    } else {
        nb *= -1;
    }
    int nb1 = nb;
    int count = 1;
    while (nb1 <= -10) {
        count *= 10;
        nb1 /= 10;
    }
    do {
        str[i++] = 48 - (nb / count) % 10;
        count /= 10;
    } while (count != 0);
    str[i] = '\0';
    return str;
}
