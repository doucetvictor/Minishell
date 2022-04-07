/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    long res = 0;
    int sign = 1;
    int i = 0;
    while (str[i] != '\0') {
        int flag = str[i] >= '0' && str[i] <= '9';
        if (str[i] == '-') {
            sign *= -1;
        } else if (flag) {
            res = res * 10 + str[i] - '0';
        }
        if (str[i] != '-' && flag && (str[i + 1] < '0' || str[i + 1] > '9')) {
            break;
        }
        i++;
    }
    res *= sign;
    if (res < -2147483648 || res > 2147483647) {
        return 0;
    }
    return res;
}
