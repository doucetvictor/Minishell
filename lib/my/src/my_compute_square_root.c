/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    long res = 0;
    int pow = 0;
    while (res < nb) {
        res = pow * pow;
        if (res == nb) {
            return pow;
        }
        if (res > 2147483647) {
            return 0;
        }
        pow++;
    }
    return 0;
}
