/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:55 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:03:47 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

t_struct	*display_u(t_struct *st, va_list ap)
{
	unsigned int	n;
	int				count;
	char			*str;

	*(st->i) += 1;
	n = va_arg(ap, unsigned int);
	count = ft_unum(n);
	str = ft_unitoa(n);
	if (checking_null(st, n, count))
		return (st);
	else
		parsing(st, count, str);
	st->length += count;
	free(str);
	return (st);
}
