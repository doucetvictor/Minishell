/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
    return str;
}
