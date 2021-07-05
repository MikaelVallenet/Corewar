/*
** EPITECH PROJECT, 2021
** Corewar ASM
** File description:
** main
*/

#include "asm.h"

int main(int ac, char **av)
{
    head_t head;

    handle_error(ac, av);
    init_head(&head, av);
    if (parse_file(&head) || head.error)
        return (84);
    file_writer(&head, av[1]);
    return (0);
}