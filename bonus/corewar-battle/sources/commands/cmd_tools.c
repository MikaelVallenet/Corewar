/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cmd_tools
*/

#include "cmd.h"

int get_execute_address(prog_t *prog)
{
    int address = prog->address + prog->pc;

    return (select_address(address));
}

int get_command_duration(int id)
{
    if (id < 1 || id > 16)
        return (-1);
    return (COMMANDS[id - 1].duration);
}

void add_pc(int *pc, int nb)
{
    *pc += nb;
    while (*pc > 65535)
        *pc -= 65536;
    while (*pc < 0)
        *pc += 65536;
}

int select_address(int address)
{
    while (address >= MEM_SIZE)
        address -= MEM_SIZE;
    while (address < 0)
        address += MEM_SIZE;
    return (address);
}