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

static void	arg_to_str_n(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->type == 'd')
		ft_ltoa_base((long int)va_arg(*ap, int), 10, 0, buff);
	if (arg->type == 'o')
		ft_ltoa_base((long int)va_arg(*ap, int), 8, 0, buff);
	if (arg->type == 'x')
		ft_ltoa_base((long int)va_arg(*ap, int), 16, 0, buff);
	if (arg->type == 'X')
		ft_ltoa_base((long int)va_arg(*ap, int), 16, 1, buff);
	if (arg->type == 'b') // BONUS
		ft_ltoa_base((long int)va_arg(*ap, int), 2, 0, buff);
	if (arg->type == 'f')
		ft_dtoa((double)va_arg(*ap, double), 6, buff);
}

int			print_arg(t_fmarg *arg, va_list *ap)
{
	char	*str;
	char	buff[65];

	if (arg->type == '%')
		return (write(1, "%", 1));
	else if (arg->type == 's' || arg->type == 'c' ||
		arg->type == 'S' || arg->type == 'C')
	{
		arg_to_str_s(arg, ap, &str);
		return (write(1, str, ft_strlen(str)));
	}
	else
	{
		arg_to_str_n(arg, ap, buff);
		return (write(1, str, ft_strlen(buff)));
	}
}
