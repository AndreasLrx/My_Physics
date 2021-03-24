/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** read file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int my_filesize(char const *filename);
char *my_strncat(char *dest, char const *src, size_t n);

static int read_file(int file, char **file_content, int file_size)
{
    int size_read;

    size_read = read(file, *file_content, file_size);
    close(file);
    if (size_read == -1) {
        free(*file_content);
        *file_content = NULL;
        return 0;
    }
    (*file_content)[file_size] = 0;
    return 1;
}

int my_readfile(char **file_content, char const *filename)
{
    int file_size = my_filesize(filename);
    int file;

    if (file_size <= 0)
        return (file_size == 0);
    file = open(filename, O_RDONLY);
    if (file == -1)
        return 0;
    *file_content = malloc(sizeof(char) * (file_size + 1));
    if (*file_content == NULL) {
        close(file);
        return 0;
    }
    return read_file(file, file_content, file_size);
}