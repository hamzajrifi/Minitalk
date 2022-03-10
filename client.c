
#include "header.h"
void    send_sin(int *bin, int PID)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (bin[i] == 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(100);
		i--;
	}
}

void    convert_binary(char **str, int PID)
{
	int		i;
	int		nbr;
	char	*tab;
	int		*bin;
	int 	j;
	int		k;

	tab = str[2];
	i = 0;
	bin = calloc(sizeof(int), 8);
	while(tab[i])
	{
		nbr = tab[i];
		j = 0;
		k = 7;
		while (k != 0)
		{
			if (nbr == 0)
				bin[j] = 0;
			else
			{
				bin[j] = nbr % 2;
				nbr = nbr / 2;
			}
			j++;
			k--;
		}
		send_sin(bin, PID);
		i++;
    }
	
	for (int i = j; i >= 0; i--)
	{
		printf("%d", bin[i]);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		write(2, "Insert Your PID \n", 18);
    	exit(1);
	}
	if (ft_atoi(av[1]) < -2)
	{
		write(2, "Insert Correct Your PID \n", 18);
    	exit(1);
	}
	if (ac == 2)
	{
		write(2, "Insert Your Message \n", 18);
    	exit(1);
	}
	check_PID(av[1]);
	convert_binary(av, ft_atoi(av[1]));
	return (0);
}