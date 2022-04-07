/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
