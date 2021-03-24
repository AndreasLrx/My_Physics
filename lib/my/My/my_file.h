/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** file fcts
*/

#ifndef MY_LIB_FILE_H
#define MY_LIB_FILE_H

int my_filesize(char const *filename);
int my_readfile(char **file_content, char const *filename);
char *my_openfile(char const *file, long size_file);

#endif /* !MY_FILE_H */