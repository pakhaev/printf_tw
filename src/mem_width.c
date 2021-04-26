/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:52:00 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:10:38 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

void	mem_width(t_struct *st)
{
	const char	*str;

	str = st->str;
	while (str[*(st->i)] >= '0' && str[*(st->i)] <= '9')
	{
		st->width = st->width * 10 + (str[*(st->i)] - '0');
		*(st->i) += 1;
	}
}

void	mem_dwidth(t_struct *st)
{
	const char *str;

	str = st->str;
	while (str[*(st->i)] >= '0' && str[*(st->i)] <= '9')
	{
		st->dot_width = st->dot_width * 10 + (str[*(st->i)] - '0');
		*(st->i) += 1;
	}
}
