/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:52:15 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:14:38 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

int		ft_numlen(int s)
{
	int		i;
	long	c;

	c = s;
	i = 0;
	if (c < 0)
		c *= -1;
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i + 1);
}

int		checking_null(t_struct *st, long int n, int count)
{
	if (st->flag_dot && !st->dot_width && n == 0 && !st->width)
		return (1);
	else if (st->flag_dot && !st->dot_width && n == 0 && st->width && \
			st->type != 'x' && st->type != 'X')
	{
		print_space(st, --count);
		return (1);
	}
	else if (st->flag_dot && !st->dot_width && n == 0 && st->width && \
			(st->type == 'x' || st->type == 'X'))
	{
		print_space(st, count);
		return (1);
	}
	return (0);
}

char	*ft_unitoa(unsigned int nb)
{
	char	*res;
	int		len;
	int		i;

	len = ft_unum(nb);
	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1 + (nb < 0 ? 1 : 0)))))
		return (NULL);
	if (nb == 0)
	{
		res[i++] = nb + 48;
		res[i] = '\0';
		return (res);
	}
	i = len - 1;
	while (nb >= 10)
	{
		res[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	res[i] = nb % 10 + 48;
	res[len] = '\0';
	return (res);
}

void	print_negative(t_struct *st, int *count, char *str)
{
	ft_putchar('-');
	*(count) = ft_strlen(str);
	st->width--;
}

int		print_p(t_struct *st)
{
	if (st->type == 'p')
	{
		write(1, "0x", 2);
		return (1);
	}
	return (0);
}
