/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** my_putnbr
*/

void my_putchar(char c);

void my_putnbr(int nb)
{
    int special_case = 0;

    if (nb == -2147483648) {
        nb = 214748364;
        my_putchar('-');
        special_case = 1;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    if (special_case == 1)
        my_putchar('8');
}