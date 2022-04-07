/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
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
        my_putchar(48 - (nb / count) % 10);
        count /= 10;
    } while (count != 0);

    return 0;
}
