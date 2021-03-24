/*
** EPITECH PROJECT, 2021
** My
** File description:
** my filesize
*/

#include <sys/stat.h>
#include <stddef.h>
#include <errno.h>

int my_filesize(char const *filename)
{
    struct stat file_stat;

    errno = 0;
    if (filename == NULL)
        return -1;
    if (stat(filename, &file_stat) == -1)
        return -1;
    if (!S_ISREG(file_stat.st_mode)) {
        return -1;
    }
    return file_stat.st_size;
}