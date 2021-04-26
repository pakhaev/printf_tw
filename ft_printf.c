/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:49:13 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 14:52:01 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_printf_str(const char *format, t_struct *st, va_list ap)
{
	int	i;

	i = 0;
	st->length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_create(st);
			i++;
			st->i = &i;
			flags(st, ap);
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			st->length++;
		}
	}
	return (st);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*st;

	if (!(st = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	st->str = format;
	va_start(ap, format);
	ft_printf_str(format, st, ap);
	va_end(ap);
	free(st);
	return (st->length);
}
