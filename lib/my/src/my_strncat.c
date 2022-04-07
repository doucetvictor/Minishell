/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** my_strncat
*/

char *my_strncat(char *dest , char const *src , int nb)
{
    int i = 0;
    int len = 0;
    while (dest[len] != '\0')
        len++;
    for (; i < nb && src[i] != '\0' ; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
