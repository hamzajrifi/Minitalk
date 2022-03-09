
#include "header.h"
void    check_av(char *av)
{
    int i;
    i = 0;
    while (av[i] != '\0')
    {
        if (av[i] > '9' || av[i] < '0')
        {
            write(2, "insert correct PID \n",20);
            exit(0);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        write(2, "insert PID  \n",20);
        return (0);
    }
    check_av(av[1]);
    kill(ft_atoi(av[1]) , SIGUSR1);
    usleep(1000);
    return (0);
}