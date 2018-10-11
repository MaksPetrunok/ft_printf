/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/10 14:52:39 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // remove me
#define uintmax_t __uintmax_t
#define intmax_t long

// sSpdDioOuUxXcC
// pdDioOuUxX

void	arg_to_str_di(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->lengthmod == emp)
		ft_lltoa_base(va_arg(*ap, int), 10, 0, buff);
	else if (arg->lengthmod == hh)
		ft_lltoa_base((signed char)va_arg(*ap, int), 10, 0, buff);
	else if (arg->lengthmod == h)
		ft_lltoa_base((short)va_arg(*ap, int), 10, 0, buff);
	else if (arg->lengthmod == l)
		ft_lltoa_base((long)va_arg(*ap, long), 10, 0, buff);
	else if (arg->lengthmod == ll)
		ft_lltoa_base((long long)va_arg(*ap, long long), 10, 0, buff);
	else if (arg->lengthmod == j)
		ft_lltoa_base((signed long long)va_arg(*ap, intmax_t), 10, 0, buff);
	else if (arg->lengthmod == z)
		ft_lltoa_base((signed long int)va_arg(*ap, size_t), 10, 0, buff);
}

void	arg_to_str_ouxX(t_fmarg *arg, va_list *ap, char *buff)
{
	unsigned long long	val;

	if (arg->lengthmod == emp)
		val = (unsigned int)va_arg(*ap, int);
	else if (arg->lengthmod == hh)
		val = (unsigned char)va_arg(*ap, int);
	else if (arg->lengthmod == h)
		val = (unsigned short)va_arg(*ap, int);
	else if (arg->lengthmod == l)
		val = (unsigned long)va_arg(*ap, unsigned long);
	else if (arg->lengthmod == ll)
		val = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (arg->lengthmod == j)
		val = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (arg->lengthmod == z)
		val = (size_t)va_arg(*ap, size_t);

	if (arg->type == 'o')
		ft_lltoa_base(val, 8, 0, buff);
	else if (arg->type == 'u')
		ft_ulltoa_base(val, 10, 0, buff);
	else if (arg->type == 'x')
		ft_lltoa_base(val, 16, 0, buff);
	else if (arg->type == 'X')
		ft_lltoa_base(val, 16, 1, buff);
	else if (arg->type == 'b')
		ft_lltoa_base(val, 2, 0, buff);
}

void	arg_to_str_f(t_fmarg *arg, va_list *ap, char *buff)
{
//printf("\nPRECISION = %d\n", arg->precision);
	if (arg->precision == -1)
		arg->precision = 6;
	ft_dtoa((double)va_arg(*ap, double), arg->precision, buff);
//printf("STRING VALUE = %s\n", buff);
//printf("%f, %d, %s\n", va_arg(*ap, double), arg->precision, buff);
//	else if (arg->type == 'p')
//		ft_lltoa_base((long int)va_arg(*ap, int), 16, 0, buff);
}
