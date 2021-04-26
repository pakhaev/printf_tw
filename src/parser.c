/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:53:51 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:24:59 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

t_struct	*ignore_flags(t_struct *st)
{
	if (st->flag_null && st->flag_dot && st->dot_width > 0)
		st->flag_null = 0;
	if (st->flag_null && st->flag_neg)
		st->flag_null = 0;
	return (st);
}

static void	display(t_struct *st, va_list ap)
{
	if (st->type == 's')
		display_s(st, ap);
	else if (st->type == 'd' || st->type == 'i')
		display_d(st, ap);
	else if (st->type == 'u')
		display_u(st, ap);
	else if (st->type == 'c')
		display_c(st, ap);
	else if (st->type == 'p')
		display_p(st, ap);
	else if (st->type == 'x')
		display_x(st, ap, 0);
	else if (st->type == 'X')
		display_x(st, ap, 1);
	else if (st->type == '%')
		display_percent(st);
}

int			parser(t_struct *st, va_list ap)
{
	int	*i;

	i = (st->i);
	ignore_flags(st);
	(st->str[*i] == 's') ? (st->type = 's') : 0;
	(st->str[*i] == 'd') ? (st->type = 'd') : 0;
	(st->str[*i] == 'i') ? (st->type = 'i') : 0;
	(st->str[*i] == 'u') ? (st->type = 'u') : 0;
	(st->str[*i] == 'c') ? (st->type = 'c') : 0;
	(st->str[*i] == 'p') ? (st->type = 'p') : 0;
	(st->str[*i] == 'x') ? (st->type = 'x') : 0;
	(st->str[*i] == 'X') ? (st->type = 'X') : 0;
	(st->str[*i] == '%') ? (st->type = '%') : 0;
	display(st, ap);
	return (st->length);
}
