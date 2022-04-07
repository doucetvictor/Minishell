/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    my_putchar(n < 0 ? 'N' : 'P');
    return 0;
}
