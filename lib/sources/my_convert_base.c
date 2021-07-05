/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_convert_base
*/

#include <stdlib.h>

int my_strlen(char *str);
char *my_addchar(char *str, char c, int position);
int my_strcmp(char *str1, char *str2);

static long long get_basic_value(char c, char *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (c == base[i])
            return (i);
    }
    return (0);
}

static long long put_base_ten(char *nbr, char *base_from)
{
    long long calcul = 0;
    long long pow = 1;

    for (int i = my_strlen(nbr) - 1; i >= 0; i--) {
        calcul += get_basic_value(nbr[i], base_from) * pow;
        pow *= my_strlen(base_from);
    }
    return (calcul);
}

static char *put_base_other(long long nb, char *base_to)
{
    char *result = malloc(sizeof(char));
    int calcul;

    result[0] = '\0';
    while (nb > 0) {
        calcul = nb % my_strlen(base_to);
        result = my_addchar(result, base_to[calcul], 1);
        nb = nb / my_strlen(base_to);
    }
    return (result);
}

char *my_convert_base(char *nbr, char *base_from, char *base_to)
{
    long long base_ten;
    char *result;

    if (my_strcmp(base_from, base_to) == 0)
        return (nbr);
    base_ten = put_base_ten(nbr, base_from);
    result = put_base_other(base_ten, base_to);
    return (result);
}