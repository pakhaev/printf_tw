/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:53:25 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:27:31 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	print_space(t_struct *st, int n)
{
	int	i;

	i = st->width - n;
	i > 0 ? st->length += i : 0;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}
