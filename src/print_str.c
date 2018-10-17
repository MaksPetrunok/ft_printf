/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:31:23 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/17 19:06:47 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // remove me

void	print_c(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	fill;
	int		n;

	fill = (a->flags & F_ZERO && !(a->flags & F_PREC)) ? '0' : ' ';
	if (!(a->flags & F_LEFT) && (n = (a->width - (MAX(a->precision, len)))) > 0)
		appendchr(buffer, fill, n);
	if ((n = (a->precision - len)) > 0 && a->width != 0)
		appendchr(buffer, ' ', n);
	appendnchr(buffer, s, len);
	if (a->flags & F_LEFT && (n = (a->width - (MAX(a->precision, len)))) > 0)
		appendchr(buffer, ' ', n);
}

void	print_s(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	fill;
	int		n;

	if (s == 0)
	{
		append(buffer, "(null)", 6);
		return ;
	}
	len = ((a->flags & F_PREC) && a->precision < len) ?
		a->precision : len;
	fill = (a->flags & F_ZERO && !(a->flags & F_PREC)) ? '0' : ' ';
	if (!(a->flags & F_LEFT) && (n = (a->width - (MAX(a->precision, len)))) > 0)
		appendchr(buffer, fill, n);
	if ((n = (a->precision - len)) > 0 && a->width != 0)
		appendchr(buffer, ' ', n);
	append(buffer, s, len);
	if (a->flags & F_LEFT && (n = (a->width - (MAX(a->precision, len)))) > 0)
		appendchr(buffer, ' ', n);
	if (a->flags & F_LONG)
		free((void *)s);
}
