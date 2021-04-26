/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unum_longnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:54:04 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:29:06 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

int		ft_unum(unsigned int s)
{
	int	i;

	i = 0;
	while (s >= 10)
	{
		s /= 10;
		i++;
	}
	return (i + 1);
}

void	ft_longnum(t_struct *st, unsigned long n)
{
	if (n > 15)
	{
		ft_longnum(st, n / 16);
		ft_longnum(st, n % 16);
	}
	else
		st->count++;
}

int		ft_longlen(unsigned long n, int i)
{
	if (n > 15)
	{
		ft_longlen(n / 16, i);
		ft_longlen(n % 16, i);
	}
	else
		i++;
	return (i);
}
