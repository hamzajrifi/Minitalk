#include "header_bonus.h"

void	check_bit(int sig)
{
	static char	tab[100000000];
	static int	i;
	static int	bit = 7;
	static int	k;


	if (sig == SIGUSR1)
		tab[i] |= (1 << bit);
	if (sig == SIGUSR2)
		tab[i] &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (tab[i] == '\0' && k == 0)
		{
			write(1, tab, i);
			i = 0;
			k = 1;
		}
		else if (tab[i] == '\0' && k == 1)
		{
			kill(ft_atoi(tab), SIGUSR2);
			usleep(100);
			k = 0;
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	write (1, "My PID it's =     ", 19);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, check_bit);
	signal(SIGUSR2, check_bit);
	while (1)
		pause();
	return (0);
}
