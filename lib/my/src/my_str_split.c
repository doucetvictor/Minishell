/*
** EPITECH PROJECT, 2021
** my_str_split.c
** File description:
** my_str_split
*/

#include <stdlib.h>

int my_str_split_getwords(char const *str, char sep)
{
    int len = 1;
    int i = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (c == sep)
            len++;
        i++;
    }
    return len;
}

int my_str_split_strlen(char const *str, char sep, int n)
{
    int len2 = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0' && len <= n) {
        char c = str[i];
        if (c == sep)
            len++;
        else if (len == n)
            len2++;
        i++;
    }
    return len2;
}

void my_str_split_cpystr(char const *str, char sep, char *word, int n)
{
    int len2 = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0' && len <= n) {
        char c = str[i];
        if (c == sep)
            len++;
        else if (len == n) {
            word[len2] = c;
            len2++;
        }
        i++;
    }
    word[len2] = '\0';
}

char ** my_str_split_noemptyline(char **out)
{
    int j = 0;
    for (int i = 0; out[i]; i++)
        if (out[i][0] != '\0')
            j++;
    char **out1 = malloc(j * 8 + 8);
    j = 0;
    for (int i = 0; out[i]; i++)
        if (out[i][0] != '\0')
            out1[j++] = out[i];
        else
            free(out[i]);
    out1[j] = 0;
    free(out);
    return out1;
}

char ** my_str_split(char const *str, char sep)
{
    int count = my_str_split_getwords(str, sep);
    char **out = malloc(count * 8 + 8);
    for (int i = 0; i < count; i++) {
        int len = my_str_split_strlen(str, sep, i);
        char *word = malloc(len + 1);
        my_str_split_cpystr(str, sep, word, i);
        word[len] = '\0';
        out[i] = word;
    }
    out[count] = 0;
    return my_str_split_noemptyline(out);
}
