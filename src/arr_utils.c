/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** arr_utils.c
*/

int arr_size(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}
