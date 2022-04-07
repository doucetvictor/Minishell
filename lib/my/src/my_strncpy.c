/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (i < n) {
        if (src[i] == '\0')
            return dest;
        dest[i] = src[i];
        i++;
    }
    if (n > i)
        dest[i] = '\0';
    return dest;
}
