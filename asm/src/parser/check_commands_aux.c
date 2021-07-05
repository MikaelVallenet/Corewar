/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** check_commands_aux
*/

#include "asm.h"
#include "parser.h"

void print_one_args_aux(head_t *head, char c, char *str, long nb)
{
    if (c == DIR2 && print_label_minus(head, c, str) == 0) {
        if (my_getlongnbr(str + 1) < 0) {
            nb = 65536 + my_getlongnbr(str + 1);
            add_buff_char(head, nb / 256);
            add_buff_char(head, nb % 256);
        } else {
            add_buff_char(head, my_getlongnbr(str + 1) / 256);
            add_buff_char(head, my_getlongnbr(str + 1) % 256);
        }
    }
    if (c == IND && print_label_ind(head, c, str) == 0) {
        if (my_getlongnbr(str) < 0) {
            nb = 65536 + my_getlongnbr(str);
            add_buff_char(head, nb / 256);
            add_buff_char(head, nb % 256);
        } else {
            add_buff_char(head, my_getlongnbr(str) / 256);
            add_buff_char(head, my_getlongnbr(str) % 256);
        }
    }
}