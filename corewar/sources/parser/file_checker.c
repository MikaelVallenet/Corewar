/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** file_checker
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"

/**
** @param char* File path
** @return int Size of file
*/
static int get_file_size(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char buff;
    int size = 0;

    if (fd < 0)
        show_error("Error: Can't open file !\n");
    for (; read(fd, &buff, 1); size++);
    return (size);
}

/**
** Verify file reading and create a buffer ( allocated )
** @param char* File path
** @param char** Address of future file content buffer
*/
void verify_file(char *path, char **buffer)
{
    int size = get_file_size(path);
    int fd = open(path, O_RDONLY);
    char *buff;

    if (fd < 0)
        show_error("Error: Can't open file.\n");
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        show_error("Error: Allocation problem.\n");
    buff[size] = '\0';
    if (read(fd, buff, size) != size)
        show_error("Error: Can't read file.\n");
    if (!(buff[0] == 0 && buff[1] == -22 && buff[2] == -125 && buff[3] == -13))
        show_error("Error: Incorrect program_file.\n");
    *buffer = buff;
}