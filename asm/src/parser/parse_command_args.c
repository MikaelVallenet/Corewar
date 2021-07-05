/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** parse_command_args
*/

#include "asm.h"
#include "parser.h"

int check_dir(char *str, int type)
{
    long value = 0;
    int i = 1;

    if (str[1] == '\0')
        return (0);
    if (str[1] == '-' && str[2] != '\0')
        i += 1;
    if (str[1] == '-' && str[2] == '\0')
        return (0);
    for (; str[i] != '\0'; i += 1)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    value = my_getlongnbr(str + 1);
    if ((type == DIR4 && (value > 4294967296 || value < -4294967296)) ||
    (type == DIR2 && (value > 65535 || value < - 65535)))
        exit_error("DIR Value too high : ./get_commands l:45");
    return (2);
}

int check_ind_label(char *str)
{
    int nb = 0;

    if (str[1] == '\0')
        return (0);
    for (int i = 1; str[i] != '\0'; i += 1) {
        for (int j = 0; LABEL_CHARS[j] != '\0'; j += 1) {
            nb += verify_char_lab(str[i], LABEL_CHARS[j]);
        }
        if (nb == 0)
            return (0);
    }
    return (3);
}

int check_ind(char *str)
{
    long value = 0;
    int i = 0;

    if (str[0] == '\0')
        exit_error("Zero in first character of arg : ./get_commands l:54");
    if (str[0] == LABEL_CHAR)
        return (check_ind_label(str));
    if (str[0] == '-' && str[1] != '\0')
        i += 1;
    for (; str[i] != '\0'; i += 1)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    value = my_getlongnbr(str);
    if (value > 65536 || value < -65536)
        exit_error("indirect value too high : ./get_commands l:60");
    return (3);
}

int check_reg(char *str)
{
    int value = 0;

    if (str[0] != 'r')
        return (0);
    if (str[1] == '\0') {
        return (0);
    }
    for (int i = 1; str[i] != '\0'; i += 1)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    value = my_getlongnbr(str + 1);
    if (value == 0 || value > REG_NUMBER)
        return (0);
    return (1);
}

int check_one_arg(int t, char *arg)
{
    int value = 0;

    if (!arg[0])
        exit_error("Zero in first character of arg : ./get_command l:86");
    if (t == NO)
        return (0);
    if (t == DIR4 || t == DIR2) {
        if (arg[0] != DIRECT_CHAR)
            return (0);
        value = (arg[1] == ':') ? check_lab(arg) : check_dir(arg, t);
        value = (t == DIR4 && value != 0) ? value + 2 : value;
    }
    if (t == IND)
        value = check_ind(arg);
    if (t == REG)
        value = check_reg(arg);
    return (value);
}