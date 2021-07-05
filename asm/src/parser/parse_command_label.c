/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** parse_command_label
*/

#include "asm.h"
#include "parser.h"

static int print_label_minus_aux(head_t *head, char c, char *str)
{
    if (c == DIR2) {
        for (int i = 0; str[i] != '\0'; i += 1) {
            label_add_pos(head->labels, str, (int [3]){head->buff_len,
            head->len_commands, 2});
            add_buff_char(head, 0);
            add_buff_char(head, 0);
            return (1);
        }
    }
    return (0);
}

int print_label_minus(head_t *head, char c, char *str)
{
    int label = 0;

    for (int i = 0; str[i] != '\0'; i += 1, label += (str[i] == ':'));
    if (label == 0)
        return (0);
    if (c == DIR4) {
        for (int i = 0; str[i] != '\0'; i += 1) {
            label_add_pos(head->labels, str, (int [3]){head->buff_len,
            head->len_commands, 4});
            add_buff_char(head, 0);
            add_buff_char(head, 0);
            add_buff_char(head, 0);
            add_buff_char(head, 0);
            return (1);
        }
    }
    return (print_label_minus_aux(head, c, str));
}

int print_label_ind(head_t *head, char c, char *str)
{
    int label = 0;

    for (int i = 0; str[i] != '\0'; label += (str[i] == ':'), i += 1);
    if (label == 0)
        return (0);
    if (c == IND) {
        for (int i = 0; str[i] != '\0'; i += 1) {
            label_add_pos(head->labels, str, (int [3]){head->buff_len,
            head->len_commands, 2});
            add_buff_char(head, 0);
            add_buff_char(head, 0);
            return (1);
        }
    }
    return (0);
}

int verify_char_lab(char a, char b)
{
    if (a != b)
        return (0);
    return (1);
}

int check_lab(char *str)
{
    int nb = 0;

    for (int i = 2; str[i] != '\0'; i += 1) {
        for (int j = 0; LABEL_CHARS[j] != '\0'; j += 1)
            nb += verify_char_lab(str[i], LABEL_CHARS[j]);
        if (nb == 0) {
            return (0);
        }
        nb = 0;
    }
    return (2);
}