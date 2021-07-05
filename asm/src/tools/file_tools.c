/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** file_tools
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

/**
** @param char* File path
** @return int Size of file
*/
int get_file_fsize(FILE *file)
{
    char buff = 0;
    int size = 0;

    fseek(file, 0, SEEK_SET);
    for (; fread(&buff, sizeof(char), 1, file); size++);
    return (size);
}

/**
** @param FILE* File descriptor of the file
** @param char** address of buffer
** @return int Size of file
*/
int fread_file(FILE *fd, char **buffer)
{
    int size = get_file_fsize(fd);
    char *buff = NULL;

    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        ALLOC_ERROR;
    buff[size] = '\0';
    fseek(fd, 0, SEEK_SET);
    if (fread(buff, sizeof(char), size, fd) != (size_t)size) {
        READ_ERROR;
    }
    *buffer = buff;
    return (size);
}