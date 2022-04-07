/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_str_to_word_array_getwords(char const *str)
{
    int len = 1;
    int i = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if ((c < '0' || c > '9')
            && (c < 'A' || c > 'Z')
            && (c < 'a' || c > 'z'))
            len++;
        i++;
    }
    return len;
}

int my_str_to_word_array_strlen(char const *str, int n)
{
    int len2 = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0' && len <= n) {
        char c = str[i];
        if ((c < '0' || c > '9')
            && (c < 'A' || c > 'Z')
            && (c < 'a' || c > 'z'))
            len++;
        else if (len == n)
            len2++;
        i++;
    }
    return len2;
}

void my_str_to_word_array_cpystr(char const *str, char *word, int n)
{
    int len2 = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0' && len <= n) {
        char c = str[i];
        if ((c < '0' || c > '9')
            && (c < 'A' || c > 'Z')
            && (c < 'a' || c > 'z'))
            len++;
        else if (len == n) {
            word[len2] = c;
            len2++;
        }
        i++;
    }
    word[len2] = '\0';
}

char ** my_str_to_word_array_noemptyline(char **out)
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
    out1[j] = 0;
    return out1;
}

char ** my_str_to_word_array(char const *str)
{
    int count = my_str_to_word_array_getwords(str);
    char **out = malloc(count * 8 + 8);
    for (int i = 0; i < count; i++) {
        int len = my_str_to_word_array_strlen(str, i);
        char *word = malloc(len + 1);
        my_str_to_word_array_cpystr(str, word, i);
        word[len] = '\0';
        out[i] = word;
    }
    out[count] = 0;
    return my_str_to_word_array_noemptyline(out);
}
