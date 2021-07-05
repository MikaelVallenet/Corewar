/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_getnbr
*/

int my_strlen(char *str);

static int is_nb(char symbol)
{
    if (symbol >= 48 && symbol <= 57)
        return (1);
    return (0);
}

static long execute_calcul(int field, int last, char *str, int negative)
{
    int pow = 1;
    long result = 0;
    int letter = 0;

    for (int y = last; y >= field; y--) {
        letter = (str[y] - 48) * pow;
        result = result + letter;
        if (negative && result > 2147483648)
            return (0);
        if (!negative && result > 2147483647)
            return (0);
        pow = pow * 10;
    }
    if (negative) {
        result = result * (-1);
    }
    return (result);
}

int my_getnbr(char *str)
{
    int negative = 0;
    int field = 0;
    int last = 0;
    int size = my_strlen(str);

    while (!is_nb(str[field])) {
        if (str[field] == '-') {
            negative = 1;
        } else if (str[field] == '+')
            negative = 0;
        field++;
    }
    for (int i = field; i < size; i++) {
        last = i;
        if (!is_nb(str[i])) {
            i = 9999999;
            last--;
        }
    }
    return (execute_calcul(field, last, str, negative));
}