/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:35:34 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/08 20:35:25 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BONUSES BEING DONE:
// 1. %b - for bynary conversion
// 2. ' flag for separating thousands
// 3. L - length modifier

#include "ft_printf.h"

#include <stdio.h> //REMOVE ME

static void	initialize_fmarg(t_fmarg *arg)
{
	arg->flags = 0;
	arg->width = 0;
	arg->precision = 6;
	arg->lengthmod = emp;
	arg->type = '\0';
}

static int	process_arg(char **str, va_list *ap)
{
	t_fmarg	arg;

	*str = *str + 1;
	initialize_fmarg(&arg);
	parse_flags(str, &arg);
/*
	printf("flags = %d\n", arg.flags);
	printf("width = %d\n", arg.width);
	printf("precision = %d\n", arg.precision);
	printf("length mod = %d\n", arg.lengthmod);
	printf("data type = %c\n", arg.type);
*/
	return (print_arg(&arg, ap));
}

int			ft_printf(const char *fmt, ...)
{
	size_t		count;
	va_list		ap;
	char		*arg;

	count = 0;
	va_start(ap, fmt);
//printf("String to be printed:\n%s\nArguments:\n", fmt);
	while ((arg = ft_strchr(fmt, '%')))
	{
		if (fmt != arg)
			count += write(1, fmt, ABS((fmt - arg)));
		count += process_arg(&arg, &ap);
		fmt = arg;
//printf("\nAFTER PARSING s = %s!!!\n", fmt);
	}
	count += write(1, fmt, ft_strlen(fmt));
	va_end(ap);
	return (count);
}
