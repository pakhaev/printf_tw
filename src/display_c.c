/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:01 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 14:57:48 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	display_c(t_struct *st, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, void*);
	*(st->i) += 1;
	st->length++;
	if (!st->flag_null && !st->flag_dot && st->width && !st->flag_neg)
		print_space(st, 1);
	write(1, &c, 1);
	if (!st->flag_null && !st->flag_dot && st->width && st->flag_neg)
		print_space(st, 1);
}
