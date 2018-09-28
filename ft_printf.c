/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:35:34 by mpetruno          #+#    #+#             */
/*   Updated: 2018/09/28 13:51:02 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

void	parse_arg(const char **fmt, va_list *ap, char *str)
{

}

void	print_arg(const char **fmt, va_list *ap, int *count)
{
	char	*argstr;
	int		len;

	if (*(*fmt + 1) == '%')
		argstr = "%";
	else
		parse_arg(fmt, ap, argstr);
	len = ft_strlen(argstr);
	count += len;
	*fmt += len + 1;
	write(1, argstr, len);
}

int		ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
		if (*fmt == '%')
			print_arg(&fmt, &ap, &count);
		else
			count += write(1, fmt++, 1);
	va_end(ap);
	return (count);
}
