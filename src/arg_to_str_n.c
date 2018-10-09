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

// sSpdDioOuUxXcC
// pdDioOuUxX

void	arg_to_str_di(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->lengthmod == hh)
		ft_ltoa_base(va_arg(*ap, signed char), 10, 0, buff);
	else if (arg->lengthmod == h)
		ft_ltoa_base(va_arg(*ap, short), 10, 0, buff);
	else if (arg->lengthmod == l)
		ft_ltoa_base(va_arg(*ap, long), 10, 0, buff);
	else if (arg->lengthmod == ll)
		ft_ltoa_base(va_arg(*ap, long long), 10, 0, buff);
	else if (arg->lengthmod == j)
		ft_ltoa_base(va_arg(*ap, intmax_t), 10, 0, buff);
	else if (arg->lengthmod == z)
		ft_ltoa_base(va_arg(*ap, size_t), 10, 0, buff);
}

void	arg_to_str_ouxX(t_fmarg *arg, va_list *ap, char *buff)
{
	unsigned long long	val;

	if (arg->lengthmod == hh)
		val = (unsigned long long)va-arg(*ap, unsigned char);
	else if (arg->lengthmod == h)
		val = (unsigned long long)va-arg(*ap, unsigned short);
	else if (arg->lengthmod == l)
		val = (unsigned long long)va-arg(*ap, unsigned long);
	else if (arg->lengthmod == ll)
		val = (unsigned long long)va-arg(*ap, unsigned long long);
	else if (arg->lengthmod == j)
		val = (unsigned long long)va-arg(*ap, uintmax_t);
	else if (arg->lengthmod == z)
		val = (unsigned long long)va-arg(*ap, size_t);

	if (arg->type == 'o')
//make lltoa_base instead of ltoa_base or in addition
		ft_ltoa_base((long int)va_arg(*ap, int), 8, 0, buff);
//	else if (arg->type == 'u')
//		ft_ultoa_base((long int)va_arg(*ap, unsigned long int), 16, 0, buff);
	else if (arg->type == 'x')
		ft_ltoa_base((long int)va_arg(*ap, int), 16, 0, buff);
	else if (arg->type == 'X')
		ft_ltoa_base((long int)va_arg(*ap, int), 16, 1, buff);
}

void	arg_to_str_bf(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->type == 'b') // BONUS
		ft_ltoa_base((long int)va_arg(*ap, int), 2, 0, buff);
	else if (arg->type == 'f')
		ft_dtoa((double)va_arg(*ap, double), 6, buff);
	if (arg->type == 'p')
		ft_ltoa_base((long int)va_arg(*ap, int), 10, 0, buff);
}
