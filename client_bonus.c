
#include "header.h"

int	ft_nchar(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}


/******************************/
void	ft_exit(void)
{
	write(2, "server does not receives a signal \n", 36);
	exit(1);
}

void	convert_binary(char *tab, int pid)
{
	int		i;
	int		nbr;
	int		k;

	i = 0;
	while (tab[i])
	{
		nbr = tab[i];
		k = 8;
		while (k != 0)
		{
			if (nbr % 2 == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_exit();
			}	
			else if (kill(pid, SIGUSR1) == -1)
				ft_exit();
			usleep(100);
			nbr = nbr / 2;
			k--;
		}
		i++;
	}
}

void	send_PID(int pid)
{
	int		n;
	char	str[10];
	int		len;

	n = getpid();
	len = ft_nchar(n);
	while (len > 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	convert_binary(str, pid);
	n = 0;
	while (n < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		n++;
	}
}
/***********************************/
//void	character_sender(char ch, int pid)
//{
//	int	bit;
//
//	bit = 7;
//	while (bit != -1)
//	{
//		if (ch & (1 << bit))
//		{
//			kill(pid, SIGUSR1);
//			write(1, "1", 1);
//		}
//		else
//		{
//			kill(pid, SIGUSR2);
//			write(1, "0", 1);
//		}
//		bit--;
//		usleep(100);
//	}
//}
/***********************************/
void	end(int	n)
{
	(void)	n;
	// if (n == SIGUSR1)
		write(1, "\n\n\n------------- done ------------\n\n\n", 38);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
	{
		write(2, "check your input \n", 19);
		exit(1);
	}
	if (ft_atoi(av[1]) < 1 || check_pid(av[1]))
	{
		write(2, "Insert Correct Your PID \n", 26);
		exit(1);
	}
	convert_binary(av[2], ft_atoi(av[1]));
	i = 0;
	while (i < 8)
	{
		kill(ft_atoi(av[1]), SIGUSR2);
		usleep(100);
		i++;
	}
	signal(SIGUSR1, end);
	send_PID(ft_atoi(av[1]));
	while (1)
	{
		pause();
	}
	
	return (0);
}
