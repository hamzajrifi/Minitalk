/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:55:46 by hjrifi            #+#    #+#             */
/*   Updated: 2022/03/14 16:59:56 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
