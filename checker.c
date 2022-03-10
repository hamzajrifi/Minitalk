#include "header.h"
void    check_PID(char *av)
{
    int i;
    i = 0;
    while (av[i] != '\0')
    {
        if (av[i] > '9' || av[i] < '0')
            {
                write(2, "Insert Correct Your PID \n", 26);
                exit(1);
            }
        i++;
    }
}