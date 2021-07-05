/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** cmd_writer
*/

#include "cmd.h"

void write_4bytes(global_t *global, int address, int value)
{
    int val1 = (value >> 24) & 255;
    int val2 = (value >> 16) & 255;
    int val3 = (value >> 8) & 255;
    int val4 = value & 255;

    global->memory[select_address(address)] = val1;
    global->memory[select_address(address + 1)] = val2;
    global->memory[select_address(address + 2)] = val3;
    global->memory[select_address(address + 3)] = val4;
}

void write_new_pc(prog_t *prog, arg_type_t args[3], int has_ocp)
{
    int add = 1;

    for (int i = 0; i < 3; i++) {
        if (args[i] == NO)
            continue;
        add = (args[i] == REG) ? (add + T_REG) : add;
        add = (args[i] == IND) ? (add + T_IND) : add;
        add = (args[i] == DIR2) ? (add + T_DIR2) : add;
        add = (args[i] == DIR4) ? (add + T_DIR4) : add;
    }
    add = (has_ocp) ? (add + 1) : add;
    add_pc(&prog->pc, add);
}