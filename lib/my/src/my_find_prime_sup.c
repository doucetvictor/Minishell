/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** my_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
