/*
** EPITECH PROJECT, 2021
** my_strcapitalize.c
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int i = 0;
    int maj = 1;
    while (str[i] != '\0') {
        int letter = str[i] >= 'a' && str[i] <= 'z';
        int space = str[i] == ' ' || str[i] == '+';
        if (!space && maj && letter)
            str[i] -= 32;
        if (!space && maj)
            maj = 0;
        if (space)
            maj = 1;
        i++;
    }
    return str;
}
