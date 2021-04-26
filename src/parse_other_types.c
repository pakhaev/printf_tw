/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:53:17 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:21:51 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

static int	print_t_nwn(t_struct *st, int count, char *str)
{
	int	if_p;

	if_p = 0;
	(st->d_negative) ? print_negative(st, &count, str) : 0;
	if_p = print_p(st) ? 2 : 1;
	(st->flag_dot) ? count += print_null(st, count) : 0;
	ft_putstr(str);
	print_space(st, count);
	return (if_p);
}

static int	print_t_nwdn(t_struct *st, int count, char *str)
{
	int	if_p;

	if_p = 0;
	if (count <= st->dot_width)
	{
		count = st->dot_width;
		(st->d_negative) ? count++ : 0;
		print_space(st, count);
	}
	else
		print_space(st, count);
	(st->d_negative) ? ft_putchar('-') : 0;
	count = ft_strlen(str);
	if_p = print_p(st) ? 2 : 1;
	print_null(st, count);
	ft_putstr(str);
	return (if_p);
}

static int	print_t_dn(t_struct *st, int count, char *str)
{
	int	if_p;

	if_p = 0;
	(st->d_negative) ? print_negative(st, &count, str) : 0;
	if_p = print_p(st) ? 2 : 1;
	print_null(st, count);
	ft_putstr(str);
	return (if_p);
}

t_struct	*parsing(t_struct *st, int count, char *str)
{
	int	if_p;

	if_p = 0;
	if (st->flag_neg && st->width && !st->flag_null)
		if_p = print_t_nwn(st, count, str);
	else if (!st->flag_neg && st->width && st->flag_dot && !st->flag_null)
		if_p = print_t_nwdn(st, count, str);
	else if (st->flag_null && st->width && st->flag_dot && !st->dot_width)
		print_space(st, count);
	else if (st->flag_dot || st->flag_null)
		if_p = print_t_dn(st, count, str);
	else if (!st->flag_neg && st->width && !st->flag_dot)
		print_space(st, count);
	if (!if_p)
	{
		(st->type == 'p' && !if_p) ? write(1, "0x", 2) : 0;
		(st->d_negative) ? print_negative(st, &count, str) : 0;
		ft_putstr(str);
	}
	return (st);
}
