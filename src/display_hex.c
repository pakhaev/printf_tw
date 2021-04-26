/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:50:17 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 15:02:34 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_func.h"

static char	hex_upper_null(unsigned long n, char *str, int *i)
{
	n == 10 ? str[*(i)] = 'a' : 0;
	n == 11 ? str[*(i)] = 'b' : 0;
	n == 12 ? str[*(i)] = 'c' : 0;
	n == 13 ? str[*(i)] = 'd' : 0;
	n == 14 ? str[*(i)] = 'e' : 0;
	n == 15 ? str[*(i)] = 'f' : 0;
	*(i) += 1;
	return (str[*(i)]);
}

char		*str_hex(unsigned long n, int upper, char *str, int *i)
{
	if (n > 15)
	{
		str_hex((n / 16), upper, str, i);
		str_hex((n % 16), upper, str, i);
	}
	else if (n < 10)
	{
		str[*(i)] = n + '0';
		*i += 1;
	}
	else if (upper == 1)
	{
		n == 10 ? str[*(i)] = 'A' : 0;
		n == 11 ? str[*(i)] = 'B' : 0;
		n == 12 ? str[*(i)] = 'C' : 0;
		n == 13 ? str[*(i)] = 'D' : 0;
		n == 14 ? str[*(i)] = 'E' : 0;
		n == 15 ? str[*(i)] = 'F' : 0;
		*i += 1;
	}
	else if (upper == 0)
		str[*(i)] = hex_upper_null(n, str, i);
	return (str);
}
