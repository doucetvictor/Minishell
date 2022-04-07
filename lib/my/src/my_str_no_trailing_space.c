/*
** EPITECH PROJECT, 2022
** my_str_no_trailing_space.c
** File description:
** my_str_no_trailing_space
*/

static int trailing_space_found(char *str, int i)
{
    for (; str[i]; i++) {
        if (str[i] != '\n' && str[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

static char* end_with_character(char *str, int i)
{
    for (int j = i; str[j]; j++) {
        if (str[j] == '\n') {
            str[i] = '\n';
            str[i + 1] = '\0';
            break;
        }
    }
    if (str[i] == ' ') {
        str[i] = '\0';
    }
    return str;
}

char* my_str_no_trailing_space(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (trailing_space_found(str, i)) {
            return end_with_character(str, i);
        }
    }
    return str;
}
