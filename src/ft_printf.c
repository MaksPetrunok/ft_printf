/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:35:34 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/19 20:07:30 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BONUSES BEING DONE:
// 1. %b - for bynary conversion
// 2. ' flag for separating thousands
// 3. L - length modifier

#include "ft_printf.h"

#include <stdio.h> //REMOVE ME
//#define PRINT_FLAGS

static void	initialize_fmarg(t_fmarg *arg)
{
	arg->flags = 0;
	arg->width = 0;
	arg->precision = -1;
	arg->type = '\0';
}

static void	process_arg(char **str, va_list *ap, t_outbuff *buffer)
{
	t_fmarg	arg;

	*str = *str + 1;
	initialize_fmarg(&arg);
	parse_flags(str, &arg);
#ifdef PRINT_FLAGS
	printf("\n===============\n");
	printf("fl #  = %d\n", arg.flags & F_HASH);
	printf("fl 0  = %d\n", arg.flags & F_ZERO);
	printf("fl +  = %d\n", arg.flags & F_PLUS);
	printf("fl sp = %d\n", arg.flags & F_SPACE);
	printf("fl -  = %d\n", arg.flags & F_LEFT);
	printf("fl '  = %d\n", arg.flags & F_THOU);
	printf("fl hh = %d\n", arg.flags & F_CHAR);
	printf("fl l  = %d\n", arg.flags & F_LONG);

	printf("width = %d\n", arg.width);
	printf("precision = %d\n", arg.precision);
	printf("data type = %c\n======================\n", arg.type);
#endif
	print_arg(&arg, ap, buffer);
}

int			ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	char		*arg;
	t_outbuff	buffer;

	initialize_output_buff(&buffer, fd);
	va_start(ap, fmt);
	while ((arg = ft_strchr(fmt, '%')))
	{
		if (fmt != arg)
			append(&buffer, fmt, arg - fmt);
		process_arg(&arg, &ap, &buffer);
		fmt = arg;
	}
	append(&buffer, fmt, -1);
	flush(&buffer);
	va_end(ap);
	return (buffer.count);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*arg;
	t_outbuff	buffer;

	initialize_output_buff(&buffer, 1);
	va_start(ap, fmt);
	while ((arg = ft_strchr(fmt, '%')))
	{
		if (fmt != arg)
			append(&buffer, fmt, arg - fmt);
		process_arg(&arg, &ap, &buffer);
		fmt = arg;
	}
	append(&buffer, fmt, -1);
	flush(&buffer);
	va_end(ap);
	return (buffer.count);
}
