#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    while (i < 4)
    {
        write(1, &av[1][i], 1);
        sleep(5);
        i++;
    }
    
   // printf("tooot%c%c%c%ctooot", av[1][0],av[1][1],av[1][2],av[1][3]);
}