/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:35:34 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/03 17:38:41 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BONUSES DONE:
// 1. %b - for bynary conversion

#include "ft_printf.h"

#include <stdio.h> //REMOVE ME
/*
static void	parse_arg(const char *fmt, va_list *ap, char **str)
{
	if (*fmt == '%')
		*str = "%";
	if (*fmt == 's')
		*str = va_arg(*ap, char *);
	if (*fmt == 'd')
		*str = ft_ltoa_base((long int)va_arg(*ap, int), 10, 0);
	if (*fmt == 'o')
		*str = ft_ltoa_base((long int)va_arg(*ap, int), 8, 0);
	if (*fmt == 'x')
		*str = ft_ltoa_base((long int)va_arg(*ap, int), 16, 0);
	if (*fmt == 'X')
		*str = ft_ltoa_base((long int)va_arg(*ap, int), 16, 1);
	if (*fmt == 'b') // BONUS
		*str = ft_ltoa_base((long int)va_arg(*ap, int), 2, 0);
	if (*fmt == 'f')
		*str = ft_dtoa((double)va_arg(*ap, double), 6);
}
*/



/* Parse argument starting from *fmt (**fmt == '%', begining of argument descr).
 * Set *fmt to the next character in the string after parsed argument.
 * Use *ap list to pull argument value.
 * Return number of printed symbols.
 */

void			initialize_fmarg(t_fmarg *arg)
{
	arg->flags = 0;
	arg->width = 0;
	arg->precision = 6;
	arg->lengthmod = '\0';
	arg->type = '\0';
}

void			parse_flags(char **str, t_fmarg *arg)
{
	char	*tmp;
	char	*fl;

	fl = FLAGS;
	while ((tmp = ft_strchr(fl, **str)) != 0)
	{
		arg->flags = arg->flags | (1 << (int)(ABS((tmp - fl))));
		(*str)++;
	}
	if (**str >= '0' && **str <= '9')
		arg->width = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		(*str)++;
//printf("Before parsing precision str=%s\n", *str);
	if (**str == '.')
		arg->precision = ft_atoi(++(*str));
	while (**str >= '0' && **str <= '9')
		(*str)++;
}

size_t	print_arg(t_fmarg *arg, va_list *ap)
{
	char	*fl;
	int		i;

	i = 0;
	fl = FLAGS;
printf("flags = %d\n", arg->flags);
	if (arg->flags > 0)
		printf("parsed flags: ");
	else
		printf("No flags found\n");
	while (arg->flags > 0)
	{
		if (arg->flags & 1 == 1)
			printf("%c", *(fl + i));
		arg->flags = arg->flags >> 1;
//printf(">>>>> %d\n", arg->flags);
		i++;
	}
	printf("\n");
	return (0);
}

size_t			process_arg(char **str, va_list *ap)
{
	t_fmarg	arg;

	*str = *str + 1;
	initialize_fmarg(&arg);
	parse_flags(str, &arg);

	printf("flags = %d\n", arg.flags);
	printf("width = %d\n", arg.width);
	printf("precision = %d\n", arg.precision);
	printf("data type = %c\n", arg.type);
	*str = *str + 2;
	return (print_arg(&arg, ap));
}

int				ft_printf(const char *fmt, ...)
{
	size_t		count;
	va_list		ap;
	char		*arg;

	count = 0;
	va_start(ap, fmt);
	while ((arg = ft_strchr(fmt, '%')))
	{
		if (fmt != arg)
			count += write(1, fmt, ABS((fmt - arg)));
		count += process_arg(&arg, &ap);
		fmt = arg;
	}
	count += write(1, fmt, ft_strlen(fmt));
	va_end(ap);
	return (count);
}
