/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/12 18:25:10 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // remove me

void	print_f(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	pr;
	int		count;
	int		flag;

	pr = (a->flags & F_ZERO) ? '0' : ' ';
	count = (a->flags & F_HASH) && (ft_strchr(s, '.') == 0);
	flag = count;
	if (a->flags & F_PLUS)
		append(buffer, "+", 1);
	else if (a->flags & F_SPACE)
		append(buffer, " ", 1);
	a->width -= count;
	if (!(a->flags & F_LEFT))
		while (a->width > len)
		{
			append(buffer, &pr, 1);
			a->width--;
		}
	append(buffer, s, len);
	while (a->width > len)
	{
		append(buffer, " ", 1);
		a->width--;
	}
	if (flag)
		append(buffer, ".", 1);
}

void	print_di(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	pr;
	int		count;

	pr = (a->flags & F_ZERO) ? '0' : ' ';
	count = 0;
	if (a->flags & F_PLUS)
		append(buffer, "+", 1);
	else if (a->flags & F_SPACE)
		append(buffer, " ", 1);
	a->width -= count;
	if (!(a->flags & F_LEFT))
		while (a->width > len)
		{
			append(buffer, &pr, 1);
			a->width--;
		}
	append(buffer, s, len);
	while (a->width > len)
	{
		append(buffer, " ", 1);
		a->width--;
	}
}

void	print_u(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	pr;
	int		count;

	pr = (a->flags & F_ZERO) ? '0' : ' ';
	count = 0;
	if (!(a->flags & F_LEFT))
		while (a->width > len)
		{
			append(buffer, &pr, 1);
			a->width--;
		}
	append(buffer, s, len);
	while (a->width > len)
	{
		append(buffer, " ", 1);
		a->width--;
	}
}

void	print_o(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	pr;
	int		count;

	pr = (a->flags & F_ZERO) ? '0' : ' ';
	count = 0;
	a->width -= (a->flags & F_HASH) > 0;
	if (!(a->flags & F_LEFT))
		while (a->width > len)
		{
			append(buffer, &pr, 1);
			a->width--;
		}
	if (a->flags & F_HASH)
		append(buffer, "0", 1);
	append(buffer, s, len);
	while (a->width > len)
	{
		append(buffer, " ", 1);
		a->width--;
	}
}

void	print_x(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	pr;
	int		count;

	pr = (a->flags & F_ZERO) ? '0' : ' ';
	count = 0;
	a->width -= (*s != '0') ? ((a->flags & F_HASH) > 0) * 2 : a->width;
	if (!(a->flags & F_LEFT))
		while (a->width > len)
		{
			append(buffer, &pr, 1);
			a->width--;
		}
	if ((a->flags & F_HASH) && *s != '0')
		append(buffer, (a->type == 'x') ? "0x" : "0X", 2);
	append(buffer, s, len);
	while (a->width > len)
	{
		append(buffer, " ", 1);
		a->width--;
	}
}
