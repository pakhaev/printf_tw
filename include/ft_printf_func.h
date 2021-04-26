/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:51:26 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/12/06 14:48:01 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNC_H
# define FT_PRINTF_FUNC_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_struct
{
	const char	*str;
	int			flag_null;
	int			flag_neg;
	int			flag_dot;
	int			dot_width;
	int			d_negative;
	int			width;
	int			count;
	char		type;
	int			length;
	int			*i;
}				t_struct;

t_struct		*ft_create(t_struct *st);

void			display_percent(t_struct *st);
void			display_c(t_struct *st, va_list ap);
t_struct		*display_d(t_struct *st, va_list ap);
t_struct		*display_p(t_struct *st, va_list ap);
t_struct		*display_s(t_struct *st, va_list ap);
t_struct		*display_u(t_struct *st, va_list ap);
t_struct		*display_x(t_struct *st, va_list ap, int flag);

void			flags(t_struct *st, va_list ap);

void			ft_putchar(const char c);
int				ft_putstr(char *s);

void			mem_width(t_struct *st);
void			mem_dwidth(t_struct *st);

int				ft_numlen(int s);
int				checking_null(t_struct *st, long int n, int count);
char			*ft_unitoa(unsigned int nb);
void			print_negative(t_struct *st, int *count, char *str);
int				print_p(t_struct *st);

void			flags_s(t_struct *st, int count, char *nstr, char *str);

t_struct		*parsing(t_struct *st, int count, char *str);

void			first_star(t_struct *st, va_list ap);
void			second_star(t_struct *st, va_list ap);

t_struct		*ignore_flags(t_struct *st);
int				parser(t_struct *st, va_list ap);

int				print_null(t_struct *st, int n);
void			print_space(t_struct *st, int n);

int				ft_unum(unsigned int s);
void			ft_longnum(t_struct *st, unsigned long n);
int				ft_longlen(unsigned long n, int i);

char			*str_hex(unsigned long n, int upper, char *str, int *i);

#endif
