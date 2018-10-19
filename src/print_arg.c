/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/19 20:10:32 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // remove

static int	wchar_to_str(wchar_t c, char *s)
{
	int	i;

	i = 0;
	if ((c >= 0 && c <= 0x7F) || MB_CUR_MAX == 1)
	{
		s[i++] = (char)c;
	}
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		s[i++] = 0xC0 | (c >> 6);
		s[i++] = 0x80 | (0x3F & c);
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		s[i++] = 0xE0 | (c >> 12);
		s[i++] = 0x80 | (0x3F & (c >> 6));
		s[i++] = 0x80 | (0x3F & c);
	}
	else if (c <= 0x1FFFFF && MB_CUR_MAX >= 4)
	{
		s[i++] = 0xF0 | (c >> 18);
		s[i++] = 0x80 | (0x3F & (c >> 12));
		s[i++] = 0x80 | (0x3F & (c >> 6));
		s[i++] = 0x80 | (0x3F & c);
	}
	s[i] = '\0';
	return (i);
}

static char	*wstr_to_str(wchar_t *ws, t_fmarg *fm)
{
	char	*s;
	int		i;
	int		added;

	i = 0;
	if (ws == 0)
		return (0);
	while (ws[i])
		i++;
	added = ((fm->precision >= 0) ?
			fm-> precision + 4 : (i * (MIN(MB_CUR_MAX, 4))));
	if ((s = (char *)malloc(added + 1)) == 0)
		return (0);
	i = 0;
	while (*ws)
	{
		added = wchar_to_str(*ws++, s + i);
		if (!(fm->flags & F_PREC) || 
				((fm->flags & F_PREC) && i + added <= fm->precision))
			i += added;
		else
			break ;
	}
	s[i] = '\0';
	return (s);
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
		*str = wstr_to_str(va_arg(*ap, wchar_t *), arg);
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
	else if (ft_strchr("u", a->type))
		print_u(a, s, len, buffer);
	else if (ft_strchr("c%", a->type))
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
	if (arg->type == 'd' || arg->type == 'i')
		arg_to_str_di(arg, ap, (str = buff));
	else if (ft_strchr("ouxXbp", arg->type))
		arg_to_str_oux(arg, ap, str = buff);
	else if (arg->type == 'f' || arg->type == 'F')
		arg_to_str_f(arg, ap, str = buff);
	else if (arg->type == 'c')
		arg_to_str_c(arg, ap, str = buff);
	else if (arg->type == 's')
		arg_to_str_s(arg, ap, &str);
	else if (ft_strchr(TYPES, arg->type) == 0)
	{
		buff[0] = arg->type;
		buff[1] = '\0';
		arg->type = 'c';
		str = buff;
	}
	len = (str) ? ft_strlen(str) : 0; // remove ternar.op.
	print_prefix(arg, str, len, buffer);
}
