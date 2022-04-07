/*
** EPITECH PROJECT, 2021
** my_sort_int_array.c
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array , int size)
{
    int i = 0;
    int j = 0;
    while (i < size) {
        if (array[j] < array[i]) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i = 0;
            j = 0;
            continue;
        }
        if (++j == size) {
            i++;
            j = i;
        }
    }
}
