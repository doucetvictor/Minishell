/*
** EPITECH PROJECT, 2021
** my_str_isupper.c
** File description:
** my_str_isupper
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' || str[i] <= 'z')
            return 0;
        i++;
    }
    return 1;
}
