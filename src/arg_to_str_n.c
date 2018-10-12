/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/12 19:19:57 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // remove me

//#define uintmax_t __uintmax_t
//#define intmax_t long

// sSpdDioOuUxXcC
// pdDioOuUxX

void	arg_to_str_di(t_fmarg *arg, va_list *ap, char *buff)
{
	if (arg->flags & F_CHAR)
		ft_lltoa_base((signed char)va_arg(*ap, int), 10, 0, buff);
	else if (arg->flags & F_SHORT)
		ft_lltoa_base((short)va_arg(*ap, int), 10, 0, buff);
	else if (arg->flags & F_LONG)
		ft_lltoa_base((long)va_arg(*ap, long), 10, 0, buff);
	else if (arg->flags & F_LLONG)
		ft_lltoa_base((long long)va_arg(*ap, long long), 10, 0, buff);
	else if (arg->flags & F_INTMAX)
		ft_lltoa_base((signed long long)va_arg(*ap, intmax_t), 10, 0, buff);
	else if (arg->flags & F_SIZE_T)
		ft_lltoa_base((signed long int)va_arg(*ap, size_t), 10, 0, buff);
	else
		ft_lltoa_base(va_arg(*ap, int), 10, 0, buff);
}

void	arg_to_str_ouxX(t_fmarg *arg, va_list *ap, char *buff)
{
	unsigned long long	val;

	if (arg->flags & F_CHAR)
		val = (unsigned char)va_arg(*ap, int);
	else if (arg->flags & F_SHORT)
		val = (unsigned short)va_arg(*ap, int);
	else if (arg->flags & F_LONG)
		val = (unsigned long)va_arg(*ap, unsigned long);
	else if (arg->flags & F_LLONG)
		val = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (arg->flags & F_INTMAX)
		val = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (arg->flags & F_SIZE_T)
		val = (size_t)va_arg(*ap, size_t);
	else
		val = (unsigned int)va_arg(*ap, int);

	if (arg->type == 'o')
		pf_ulltoa_base(val, 8, arg, buff);
	else if (arg->type == 'u')
		pf_ulltoa_base(val, 10, arg, buff);
	else if (arg->type == 'x')
		pf_ulltoa_base(val, 16, arg, buff);
	else if (arg->type == 'X')
		pf_ulltoa_base(val, 16, arg, buff);
	else if (arg->type == 'b')
		pf_ulltoa_base(val, 2, arg, buff);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>\n>>>>>>>>>>>>>>>>>> %s\n", buff);
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
