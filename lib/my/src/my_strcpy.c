/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (1) {
        dest[i] = src[i];
        if (src[i++] == '\0')
            break;
    }
    return dest;
}
