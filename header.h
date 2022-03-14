/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:00:50 by hjrifi            #+#    #+#             */
/*   Updated: 2022/03/14 17:20:17 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
int		check_pid(char *av);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
int		ft_strlen(char *str);
#endif