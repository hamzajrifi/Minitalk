/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:55:57 by hjrifi            #+#    #+#             */
/*   Updated: 2022/03/14 17:31:44 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
					write(2, "problime when send signal \n", 28);
			}	
			else if (kill(PID, SIGUSR1) == -1)
				write(2, "problime when send signal \n", 28);
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
