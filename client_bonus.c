
#include "header_bonus.h"

void	ft_exit(void)
{
	write(2, "server does not receives a signal \n", 36);
	exit(1);
}
/***********************************/
void	convert_binary(char ch, int pid)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (ch & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
					ft_exit();
		}
		else if (kill(pid, SIGUSR2) == -1)
			ft_exit();
		bit--;
		usleep(100);
	}
}
/***********************************/

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

void	send_pid(int pid)
{
	int		n;
	char	str[10];
	int		len;

	n = getpid();
	len = ft_nchar(n);
	while (len >= 1)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
		//printf("str[len = (%c)\n", str[len + 1]);
	convert_binary('\0', pid);
	n = 1;
	while (str[n])
	{
		convert_binary(str[n], pid);
		n++;
	}
	convert_binary('\0', pid);
}

void	ft_end(int	n)
{
	// (void)	n;
	if (n == SIGUSR1)
		write(1, "------------- done ------------\n", 33);
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
	i = 0;
	while (av[2][i])
		convert_binary(av[2][i++], ft_atoi(av[1]));
	send_pid(ft_atoi(av[1]));
	signal(SIGUSR1, ft_end);
	while (1)
		pause();

	return (0);
}
