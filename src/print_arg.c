/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/08 19:42:41 by mpetruno         ###   ########.fr       */
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
/*
static void	arg_to_str_di(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->type == 'd')
		ft_ltoa_base((long int)va_arg(*ap, int), 10, 0, buff);
}

static void	arg_to_str_ouxX(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->type == 'o')
		ft_ltoa_base((long int)va_arg(*ap, int), 8, 0, buff);
	else if (arg->type == 'x')
		ft_ltoa_base((long int)va_arg(*ap, int), 16, 0, buff);
	else if (arg->type == 'X')
		ft_ltoa_base((long int)va_arg(*ap, int), 16, 1, buff);
}

static void	arg_to_str_bf(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->type == 'b') // BONUS
		ft_ltoa_base((long int)va_arg(*ap, int), 2, 0, buff);
	else if (arg->type == 'f')
		ft_dtoa((double)va_arg(*ap, double), 6, buff);
}
*/
int			print_arg(t_fmarg *arg, va_list *ap)
{
	char	*str;
	char	buff[65];
	int		count;
	int		len;

	count = 0;
	if (arg->type == '%')
		str = "%";
	else if (ft_strchr("sScC", arg->type))
		arg_to_str_s(arg, ap, &str);
	else if (ft_strchr("di", arg->type))
		arg_to_str_di(arg, ap, str = buff);
	else if (ft_strchr("ouxX", arg->type))
		arg_to_str_ouxX(arg, ap, str = buff);
	else if (ft_strchr("bf", arg->type))
		arg_to_str_bf(arg, ap, str = buff);
	len = ft_strlen(str);
//	count += print_prefix();
	count += write(1, str, len);
//	count += print_suffix();
	return (count);
}
