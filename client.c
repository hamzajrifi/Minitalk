/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:55:57 by hjrifi            #+#    #+#             */
/*   Updated: 2022/03/14 18:54:28 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(void)
{
	write(2, "server does not receives a signal \n", 36);
	exit(1);
}

void	convert_binary(char *tab, int PID)
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
				if (kill(PID, SIGUSR2) == -1)
					ft_exit();
			}	
			else if (kill(PID, SIGUSR1) == -1)
				ft_exit();
			usleep(100);
			nbr = nbr / 2;
			k--;
		}
		i++;
	}
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
	return (0);
}
