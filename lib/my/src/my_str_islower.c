/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' || str[i] <= 'Z')
            return 0;
        i++;
    }
    return 1;
}
