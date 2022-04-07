/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        int flag = str[i] < 'A' || str[i] > 'Z';
        int flag1 = str[i] < 'a' || str[i] > 'z';
        if (flag && flag1)
            return 0;
        i++;
    }
    return 1;
}
