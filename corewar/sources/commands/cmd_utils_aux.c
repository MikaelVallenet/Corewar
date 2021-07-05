/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** cmd_utils_aux
*/

#include "cmd.h"

int get_type_size(arg_type_t type)
{
    switch (type) {
    case REG:
        return (T_REG);
        break;
    case IND:
        return (T_IND);
        break;
    case DIR2:
        return (T_DIR2);
        break;
    case DIR4:
        return (T_DIR4);
        break;
    }
    return (0);
}