/*
** EPITECH PROJECT, 2022
** my_read_file.c
** File description:
** my_read_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int my_read_file(char *pathname, char **out)
{
    struct stat sb;
    if (stat(pathname, &sb))
        return -1;

    int len = sb.st_size;
    *out = malloc(len + 1);
    *(out + len) = '\0';

    int fd = open(pathname, O_RDONLY);
    if (fd == -1)
        return -1;

    int res = read(fd, *out, len);
    close(fd);
    return res;
}
