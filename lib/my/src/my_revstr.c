/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        int j = len - i - 1;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}
