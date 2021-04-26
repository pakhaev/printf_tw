/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:51:42 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:16:22 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	ft_putchar(const char c)
{
	write(1, &c, sizeof(char));
}

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
