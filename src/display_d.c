/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:08 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 14:56:01 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

t_struct	*display_d(t_struct *st, va_list ap)
{
	int		n;
	int		count;
	char	*str;

	*(st->i) += 1;
	n = va_arg(ap, int);
	count = ft_numlen(n);
	if (n < 0)
	{
		n *= -1;
		st->d_negative = 1;
		count++;
	}
	str = ft_unitoa(n);
	if (checking_null(st, n, count))
		return (st);
	else
		parsing(st, count, str);
	st->length += count;
	free(str);
	return (st);
}
