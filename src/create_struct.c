/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:49:51 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 14:54:44 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

t_struct	*ft_create(t_struct *st)
{
	st->flag_null = 0;
	st->flag_neg = 0;
	st->flag_dot = 0;
	st->dot_width = 0;
	st->count = 0;
	st->width = 0;
	st->type = '\0';
	st->d_negative = 0;
	st->i = 0;
	return (st);
}
