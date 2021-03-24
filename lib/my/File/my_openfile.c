/*
** EPITECH PROJECT, 2021
** MyWorld
** File description:
** my_openfile.c
*/

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *my_openfile(char const *file, long size_file)
{
    int fd = 0;
    int reader = 0;
    char *buffer;

    if (size_file <= 0)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(*(buffer))* size_file + 1);
    reader = read(fd, buffer, size_file);
    close(fd);
    if (reader == -1) {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}
