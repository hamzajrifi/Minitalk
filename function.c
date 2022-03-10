#include "header.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_puts(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1, &str[i],1);
        i++;
    }
    write(1, "\n", 1);
}

int ft_atoi(char *str)
{
    long res;
    long sin;
    long i;

    i = 0;
    sin = 1;
    res = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            sin = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10 )+ str[i]- 48;
        i++;
    }
    if (sin < 0)
    {
        ft_puts("check your PID correct ");
        exit(1);
    }
    return (res * sin);
}

void    ft_putnbr(int nbr)
{
    if (nbr < -1)
    {
        write(2, "Insert Correct Your PID \n", 8);
        exit(1);
    }
    if (nbr <= 9)
        ft_putchar(nbr + 48);
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}
