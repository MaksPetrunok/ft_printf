/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:35:34 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/01 22:54:17 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

void	parse_arg(const char *fmt, va_list *ap, char **str)
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

void	print_arg(const char **fmt, va_list *ap, size_t *count)
{
	char	*argstr;
	int		len;

	parse_arg(*fmt + 1, ap, &argstr);
	len = ft_strlen(argstr);
	count += len;
	*fmt += 2; //count actual number of sumbols used as arguments
	write(1, argstr, len);
}

int		ft_printf(const char *fmt, ...)
{
	size_t	count;
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
