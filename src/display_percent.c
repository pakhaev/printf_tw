/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:34 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 14:58:51 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	display_percent(t_struct *st)
{
	int	fl;

	fl = 0;
	*(st->i) += 1;
	st->length++;
	if (st->flag_neg)
	{
		ft_putchar('%');
		print_space(st, 1);
		fl = 1;
	}
	else if (st->flag_null && !st->flag_neg)
		print_null(st, 1);
	else if (!st->flag_null && st->width)
		print_space(st, 1);
	if (!fl)
		ft_putchar('%');
}
