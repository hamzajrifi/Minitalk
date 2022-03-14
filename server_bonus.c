#include "header.h"

//void	check_bit(int i)
//{
//	static char	buffer[100000000];
//	static int	counter = 0;
//	static int	bit = 7;
//
//	if (i == SIGUSR1)
//	{
//		buffer[counter] |= (1 << bit);
//			write(1, "1", 1);
//	}
//	if (i == SIGUSR2)
//		{
//		buffer[counter] &= ~(1 << bit);
//			write(1, "0", 1);
//		}
//	bit--;
//	if (bit == -1)
//	{
//		bit = 7;
//		if (buffer[counter] == '\0')
//		{
//			write(1, buffer, counter);
//			counter = 0;
//		}
//		else
//		{
//			counter++;
//		}
//	}
//}

void	ft_print_str(int j, char *tab)
{
	static int	k;

	if (k == 0)
	{
		while (j > k)
			ft_putchar(tab[k++]);
		k = 1;
	}
	else if (k != 0)
	{
		k = 0;
		//printf("(%s)\n", tab);
		kill(ft_atoi(++tab), SIGUSR1);
		usleep(100);
	}
}

void	check_bit(int sig)
{
	static int	dec;
	static int	i;
	static int	j;
	static int	base = 1;
	static char	tab[999999999999];

	if (sig == SIGUSR1)
	{
		dec = dec + base;
		i++;
	}
	else
		i++;
	base = base * 2;
	if (i == 8)
	{
		tab[j] = dec;
		if (dec == 0)
		{
			ft_print_str(j, tab);
			j = -1;	
		}
		j++;
		base = 1;
		dec = 0;
		i = 0;
	}
}

// if (dec == 0)
		// {
			// if (k == 0)
			// {
				// ft_print_str(j, tab);
				// k++;
				// j = -1;
				// tab[0] = '\0';
			// }
			// else if (k == 1)
			// {
				// k = 0;
				// kill(ft_atoi(tab), SIGUSR1);
				// usleep(100);
				// j = -2;
			// }	
		// }
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
