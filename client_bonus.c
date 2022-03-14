
#include "header.h"
//void	send_sin(int *bin, int PID)
//{
//	int i;
//
//	i = 7;
//	while (0 <= i)
//	{
//		if (bin[i] == 1)
//			kill(PID, SIGUSR1);
//		else
//			kill(PID, SIGUSR2);
//		usleep(50);
//		i--;
//	}
//}

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
void	convert_binary(char *tab, int PID)
{
	int		i;
	int		nbr;
	//int		bin[8];
	int		k;

	i = 0;
	while(tab[i])
	{
		nbr = tab[i];
		k = 8;
		while (k != 0)
		{
			if (nbr % 2 == 0)
				kill(PID, SIGUSR2);
			else
				kill(PID, SIGUSR1);
			usleep(50);
			nbr = nbr / 2;
			k--;
		}
		i++;
	}
	if (tab[i] == '\0')
	{
		i = 0;
		while (i < 8)
		{
			kill(PID, SIGUSR2);
			usleep(50);
			i++;
		}
	}
}

void	send_PID(int PID)
{
	int		n;
	char	*str;
	int		len;

	n = getpid();
	len = ft_nchar(n);
	str = malloc (sizeof(char) * len);
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	printf("pid client = %s \n", str);
	convert_binary(str, PID);
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

int	main(int ac, char **av)
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
	//int i = 0;
	//while (av[2][i])
	//{
	//	
	//	character_sender(av[2][i], ft_atoi(av[1]));
	//	i++;
	//}
	//character_sender(av[2][i], ft_atoi(av[1]));
	convert_binary(av[2], ft_atoi(av[1]));
	send_PID(ft_atoi(av[1]));
	return (0);
}