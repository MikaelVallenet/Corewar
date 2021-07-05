/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** error_handler
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

/**
** Show help and exit if required.
** @param int argc
** @param char** argv
*/
void show_help(int argc, char **argv)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n./corewar [-dump nbr_cyle] [[-n prog_number] [-a lo"
        "ad_address] prog_name ...\nDESCRIPTION\n-dump nbr_cycle dumps the me"
        "mory after the nbr_cycle execution (if the round isn't already over)"
        " with the following format: 32 bytes/line in hexadecimal (AOBCDEFE1D"
        "D3...)\n-n prog_number sets the next program's number. By default, t"
        "he first free number in the parameter order\n-a load_address sets th"
        "e next program's loading address. When no address is specified, opti"
        "mize the address so that the processes are as far awat from each as "
        "possible. The addresses are MEM_SIZE modulo.\n");
        _exit(0);
    }
}

/**
** Send message on error output and exit 84
** @param char* Error message
*/
void show_error(char *msg)
{
    endwin();
    write(2, msg, my_strlen(msg));
    exit(84);
}