/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:47 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:06:19 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

t_struct	*display_s(t_struct *st, va_list ap)
{
	char	*str;
	int		count;
	char	*nstr;

	*(st->i) += 1;
	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	if (st->dot_width < 0)
	{
		st->dot_width = ft_strlen(str);
	}
	if (!(nstr = (char*)malloc(sizeof(char) * (st->dot_width + 1))))
		return (st);
	count = ft_strlen(str);
	nstr[st->dot_width] = '\0';
	flags_s(st, count, nstr, str);
	if (st->flag_dot)
		st->length += ft_strlen(nstr);
	else
		st->length += ft_strlen(str);
	free(nstr);
	return (st);
}
