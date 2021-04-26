/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:51:02 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:07:35 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

t_struct	*display_x(t_struct *st, va_list ap, int flag)
{
	unsigned int	n;
	int				i;
	int				count;
	char			*str;

	*(st->i) += 1;
	n = va_arg(ap, unsigned int);
	count = 0;
	if (checking_null(st, n, count))
		return (st);
	else
	{
		ft_longnum(st, n);
		i = st->count;
		str = (char*)malloc(sizeof(char) * (i + 1));
		count = st->count;
		st->length += count;
		i = 0;
		str = str_hex(n, flag, str, &i);
		str[i] = '\0';
		parsing(st, count, str);
	}
	free(str);
	return (st);
}
