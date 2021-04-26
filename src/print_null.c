/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:53:04 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:26:54 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

int	print_null(t_struct *st, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (st->flag_null && st->dot_width < 0)
		i = st->width - n;
	else if (!st->flag_dot)
		i = st->width - n;
	else
		i = st->dot_width - n;
	i > 0 ? st->length += i : 0;
	i > 0 ? count = i : 0;
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
	return (count);
}
