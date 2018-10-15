/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/15 21:39:02 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	wchar_to_str(wchar_t c, char *s)
{
	if (c >= 0 && c <= 0x7F)
	{
		s[0] = (char)c;
		s[1] = 0;
	}
	else if (c >= 0x80 && c <= 0xFF)
	{
		s[0] = (128 + 64) | (c >> 6);
		s[1] = 128 | c - ((c >> 6) << 6);
		s[2] = 0;
	}
}

static void	arg_to_str_c(t_fmarg *arg, va_list *ap, char *str)
{
	if (arg->type == 'c' && (arg->flags & F_LONG))
		wchar_to_str(va_arg(*ap, wchar_t), str);
	else if (arg->type == 'c')
	{
		*str = (unsigned char)va_arg(*ap, int);
		*(str + 1) = '\0';
	}
}

static void	arg_to_str_s(t_fmarg *arg, va_list *ap, char **str)
{
	if (arg->type == 's' && (arg->flags & F_LONG))
		*str = va_arg(*ap, char *);
	else if (arg->type == 's')
		*str = va_arg(*ap, char *);
}

static void	print_prefix(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	if (a->type == 'd' || a->type == 'i')
		print_di(a, s, len, buffer);
	else if (a->type == 'o')
		print_o(a, s, len, buffer);
	else if (a->type == 'f' || a->type == 'F')
		print_f(a, s, len, buffer);
	else if (ft_strchr("xpXb", a->type))
		print_x(a, s, len, buffer);
	else if (ft_strchr("u%", a->type))
		print_u(a, s, len, buffer);
	else if (ft_strchr("c", a->type))
		print_c(a, s, MAX(1, len), buffer);
	else if (ft_strchr("s", a->type))
		print_s(a, s, len, buffer);
}

void		print_arg(t_fmarg *arg, va_list *ap, t_outbuff *buffer)
{
	char	*str;
	char	buff[NTOA_BUFF_SIZE];
	int		len;

	if (arg->type == '\0')
		return ;
	str = "%";
	if (ft_strchr("di", arg->type))
		arg_to_str_di(arg, ap, (str = buff));
	else if (ft_strchr("ouxXbp", arg->type))
		arg_to_str_ouxX(arg, ap, str = buff);
	else if (ft_strchr("fF", arg->type))
		arg_to_str_f(arg, ap, str = buff);
	else if (ft_strchr("c", arg->type))
		arg_to_str_c(arg, ap, str = buff);
	else if (ft_strchr("s", arg->type))
		arg_to_str_s(arg, ap, &str);
	len = (str) ? ft_strlen(str) : 0;
	print_prefix(arg, str, len, buffer);
}
