/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** my_strstr
*/

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (str[i] != '\0') {
        if (to_find[j] == '\0')
            return str + k;
        if (str[i] == to_find[j] && j == 0)
            k = i;
        if (str[i] == to_find[j]) {
            j++;
        } else {
            j = 0;
            k = 0;
        }
        i++;
    }
    return 0;
}
