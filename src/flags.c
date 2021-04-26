/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:51:09 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:09:29 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	flags(t_struct *st, va_list ap)
{
	while (st->str[*(st->i)])
	{
		if (st->str[*(st->i)] == '0')
			st->flag_null = 1;
		if (st->str[*(st->i)] == '-')
			st->flag_neg = 1;
		if (st->str[*(st->i)] != '0' && st->str[*(st->i)] != '-')
			break ;
		*(st->i) += 1;
	}
	if (st->str[*(st->i)] == '*')
		first_star(st, ap);
	if (st->str[*(st->i)] > '0' && st->str[*(st->i)] <= '9')
		mem_width(st);
	if (st->str[*(st->i)] == '.')
	{
		st->flag_dot = 1;
		*(st->i) += 1;
	}
	if (st->str[*(st->i)] == '*')
		second_star(st, ap);
	if (st->str[*(st->i)] >= '0' && st->str[*(st->i)] <= '9')
		mem_dwidth(st);
	parser(st, ap);
}
