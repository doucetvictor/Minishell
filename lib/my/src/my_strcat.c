/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** my_strcat
*/

char *my_strcat(char *dest , char const *src)
{
    int i = 0;
    int len = 0;
    while (dest[len] != '\0')
        len++;
    for (; src[i] != '\0' ; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
