/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:56:12 by hjrifi            #+#    #+#             */
/*   Updated: 2022/03/14 18:01:04 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_str(int j, char *tab)
{
	static int	k;

	while (j > k)
	{
		ft_putchar(tab[k]);
		k++;
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
			ft_print_str(j, tab);
		j++;
		base = 1;
		dec = 0;
		i = 0;
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
