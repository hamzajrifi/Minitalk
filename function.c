#include "header.h"

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
    return (res * sin);
}