/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:24 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:00:58 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

static int	write_null(t_struct *st, unsigned long address, int count)
{
	if (checking_null(st, address, ++count))
	{
		write(1, "0x", 2);
		st->length += 2;
		return (1);
	}
	return (0);
}

t_struct	*display_p(t_struct *st, va_list ap)
{
	unsigned long	address;
	int				count;
	int				i;
	char			*str;

	count = 2;
	*(st->i) += 1;
	address = (unsigned long)(va_arg(ap, void*));
	if (write_null(st, address, count))
		return (st);
	else
	{
		ft_longnum(st, address);
		i = st->count;
		str = (char*)malloc(sizeof(char) * (i + 1));
		count = st->count;
		st->length += count + 2;
		st->width -= 2;
		i = 0;
		str = str_hex(address, 0, str, &i);
		str[i] = '\0';
		parsing(st, count, str);
	}
	free(str);
	return (st);
}
