/*
** EPITECH PROJECT, 2021
** B-CPE-201-LYN-2-1-corewar-maxime.premont
** File description:
** my_getlongnbr
*/

int my_strlen(char *str);

static long calcul_sign(char const *str, long value)
{
    for (int j = 0; str[j] == '+' || str[j] == '-'; j++)
        if (str[j] == '-')
            value = value * -1;
    return (value);
}

long my_getlongnbr(char const *str)
{
    long value = 0;
    int pos = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 && str[i] != '-' && str[i] != '+') ||
        str[i] > 57 || (str[i] < 48 && pos == 1))
            return (calcul_sign(str, value));
        if (str[i] > 47 && str[i] < 58) {
            pos = 1;
            value = (value * 10) + (str[i] - 48);
        }
    }
    return (calcul_sign(str, value));
}