
#include "header.h"

char	*convert_dicimal(int *bin)
{
	int i;
	//char *tab_dec;
	int base;
	int dec;

	base =1;
	dec = 0;
	i = 7;
	 while ( i > 0)  
    {
        dec = dec + bin[i] * base;
        base = base * 2;
		i--;
	}
	printf("dec = %c \n", dec);
	return (NULL);
}

void check_bit(int sig)
{
	static int	i;
	static int bin[8];

	if (sig == SIGUSR1)
		bin[i] = 1;
	else
		bin[i] = 0;
	i++;
	if (i == 8)
	{
		convert_dicimal(bin);
	}
}

void	ft_catch()
{
	signal(SIGUSR1, check_bit);
	signal(SIGUSR2, check_bit);
}

int main()
{
	write (1, "My PID it's =     ", 19);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	ft_catch();
	while (1)
		pause();
}
