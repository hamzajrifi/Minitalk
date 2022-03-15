/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:55:46 by hjrifi            #+#    #+#             */
/*   Updated: 2022/03/15 07:57:22 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	check_pid(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] > '9' || av[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(void)
{
	write(2, "server does not receives a signal \n", 36);
	exit(1);
}
