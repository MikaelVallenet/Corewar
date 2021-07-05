/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** error_handler
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

/**
** Send message on error output and exit 84
** @param char* Error message
*/
void exit_error(char *msg)
{
    write(2, "Error: ", 7);
    write(2, msg, my_strlen(msg));
    write(2, "\n", 1);
    exit(84);
}

static void show_help(int argc, char **argv)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in"
        " assembly language to be converted into file_name.cor, an executable"
        " in Virtual Machine\n");
        exit(0);
    }
}

static void filepath_verify(char *filepath)
{
    int i = 0;

    for (; filepath[i]; i++);
    if (i <= 2 || my_strncmp(filepath + i - 2, ".s", 2) != 0)
        exit_error("Incorect file extension. \".s\" needed.");
}

/**
** Handle error and create file buffer
** @param int argc
** @param char** argv
** @param char** The future file buffer
*/
void handle_error(int argc, char **argv)
{
    show_help(argc, argv);
    if (argc != 2)
        NB_ARGS_ERROR;
    filepath_verify(argv[1]);
}