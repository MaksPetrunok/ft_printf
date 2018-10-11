/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/10 19:00:41 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // remove me

int	print_f(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;
	int		flag;

	pr = (a->fl_zero) ? '0' : ' ';
	count = a->fl_sharp && (ft_strchr(s, '.') == 0);
	flag = count;
	if (a->fl_plus)
		count += write(1, "+", 1);
	else if (a->fl_sp)
		count += write(1, " ", 1);
	a->width -= count;
	if (!(a->fl_minus))
		while (a->width > len)
		{
			count += write(1, &pr, 1);
			a->width--;
		}
	count += write(1, s, len);
	while (a->width > len)
	{
		count += write(1, " ", 1);
		a->width--;
	}
	if (flag)
		write(1, ".", 1);
	return (count);
}

int	print_di(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;

	pr = (a->fl_zero) ? '0' : ' ';
	count = 0;
	if (a->fl_plus)
		count += write(1, "+", 1);
	else if (a->fl_sp)
		count += write(1, " ", 1);
	a->width -= count;
	if (!(a->fl_minus))
		while (a->width > len)
		{
			count += write(1, &pr, 1);
			a->width--;
		}
	count += write(1, s, len);
	while (a->width > len)
	{
		count += write(1, " ", 1);
		a->width--;
	}
	return (count);
}

int	print_u(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;

	pr = (a->fl_zero) ? '0' : ' ';
	count = 0;
	if (!a->fl_minus)
		while (a->width > len)
		{
			count += write(1, &pr, 1);
			a->width--;
		}
	count += write(1, s, len);
	while (a->width > len)
	{
		count += write(1, " ", 1);
		a->width--;
	}
	return (count);
}

int	print_o(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;

	pr = (a->fl_zero) ? '0' : ' ';
	count = 0;
	a->width -= a->fl_sharp;
	if (!a->fl_minus)
		while (a->width > len)
		{
			count += write(1, &pr, 1);
			a->width--;
		}
	if (a->fl_sharp)
		count += write(1, "0", 1);
	count += write(1, s, len);
	while (a->width > len)
	{
		count += write(1, " ", 1);
		a->width--;
	}
	return (count);
}

int	print_x(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;

	pr = (a->fl_zero) ? '0' : ' ';
	count = 0;
	a->width -= a->fl_sharp * 2;
	if (!a->fl_minus)
		while (a->width > len)
		{
			count += write(1, &pr, 1);
			a->width--;
		}
	if (a->fl_sharp)
		count += write(1, (a->type == 'x') ? "0x" : "0X", 2);
	count += write(1, s, len);
	while (a->width > len)
	{
		count += write(1, " ", 1);
		a->width--;
	}
	return (count);
}
