/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:06:45 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:22:55 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	first_star(t_struct *st, va_list ap)
{
	int	star_arg;

	*(st->i) += 1;
	star_arg = va_arg(ap, int);
	if (star_arg < 0)
	{
		st->flag_neg = 1;
		star_arg *= -1;
	}
	st->width = star_arg;
}

void	second_star(t_struct *st, va_list ap)
{
	int	star_arg;

	*(st->i) += 1;
	star_arg = va_arg(ap, int);
	st->dot_width = star_arg;
}
