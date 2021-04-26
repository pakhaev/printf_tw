/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:52:33 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:18:37 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

static void	disp_s_cspc(t_struct *st, int count)
{
	count = 0;
	print_space(st, count);
}

static void	disp_s_nd(t_struct *st, int count, char *nstr, char *str)
{
	ft_strlcpy(nstr, str, st->dot_width + 1);
	count = ft_putstr(nstr);
	print_space(st, count);
}

static void	disp_s_wd(t_struct *st, int count, char *nstr, char *str)
{
	ft_strlcpy(nstr, str, st->dot_width + 1);
	count = ft_strlen(nstr);
	print_space(st, count);
	ft_putstr(nstr);
}

void		flags_s(t_struct *st, int count, char *nstr, char *str)
{
	if (st->flag_null)
	{
		print_null(st, count);
		ft_putstr(str);
	}
	else if (st->width && st->flag_dot && !st->dot_width)
		disp_s_cspc(st, count);
	else if (st->flag_neg && !st->flag_dot)
	{
		count = ft_putstr(str);
		print_space(st, count);
	}
	else if (st->flag_neg && st->flag_dot)
		disp_s_nd(st, count, nstr, str);
	else if (st->width && st->dot_width)
		disp_s_wd(st, count, nstr, str);
	else if (st->width)
	{
		print_space(st, ft_strlen(str));
		ft_putstr(str);
	}
	else if (st->flag_dot)
		disp_s_nd(st, count, nstr, str);
	else
		ft_putstr(str);
}
