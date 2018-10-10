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

#include <stdio.h>

static void	arg_to_str_s(t_fmarg *arg, va_list *ap, char **str)
{
	if (arg->type == 's' && arg->lengthmod == 0)
		*str = va_arg(*ap, char *);
	if (arg->type == 'c' && arg->lengthmod == 0)
		*str = va_arg(*ap, char *);
	
}

int	print_pr_di(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;

	pr = (ft_strchr(a->flags, '0') != 0) ? '0' : ' ';
	count = 0;
	if (ft_strchr(a->flags, '+'))
		count += write(1, "+", 1);
	else if (ft_strchr(a->flags, ' '))
		count += write(1, " ", 1);
	a->width -= count;
	if (ft_strchr(a->flags, '-') == 0)
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

int	print_pr_o(t_fmarg *a, char *s, int len)
{
	char	pr;
	int		count;

	pr = (ft_strchr(a->flags, '0') != 0) ? '0' : ' ';
	count = 0;
	if (ft_strchr(a->flags, '+'))
		count += write(1, "+", 1);
	else if (ft_strchr(a->flags, ' '))
		count += write(1, " ", 1);
	a->width -= count;
	if (ft_strchr(a->flags, '-') == 0)
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
static int	print_prefix(t_fmarg *a, char *s, int len)
{
	if (ft_strchr("di", a->type))
		return (print_pr_di(a, s, len));
//	else if (ft_strchr("ouxX", a->type))
//		return (printf_pr_ouxX(a, s, len));
//	else if (ft_strchr("cC%", arg->type))
//		return (printf_pr_c(a, s, len));
	return (0);
}

int			print_arg(t_fmarg *arg, va_list *ap)
{
	char	*str;
	char	buff[65];
	int		count;
	int		len;


	count = 0;
	if (ft_strchr("sScC", arg->type))
		arg_to_str_s(arg, ap, &str);
	else if (ft_strchr("di", arg->type))
		arg_to_str_di(arg, ap, str = buff);
//	else if (ft_strchr("ouxX", arg->type))
//		arg_to_str_ouxX(arg, ap, str = buff);
//	else if (ft_strchr("bf", arg->type))
//		arg_to_str_bf(arg, ap, str = buff);
	else
		str = "%";
	
	len = ft_strlen(str);
	count += print_prefix(arg, str, len);
//	count += write(1, str, len);
//	count += print_suffix();
	return (count);
}
