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

void	free_arglist(t_list arg_list)
{
}

static size_t	print_arg(t_fmarg arg)
{
	return (0);
}

/* Parse argument starting from *fmt (**fmt == '%', begining of argument descr).
 * Set *fmt to the next character in the string after parsed argument.
 * Use *ap list to pull argument value.
 * Return number of printed symbols.
 */

size_t			process_arg(char **str, va_list *ap, t_avlist *av)
{
	t_fmarg	arg;
printf("LIST = %p\n", av);
	arg.data = get_arg_data(get_arg_num(str), ap, av);
	printf("Before reading data\n");
	printf("argument value: %p\n", arg.data);
	printf("after reading\n");

	printf("\n******* NEW Arg ********* %s\n", *str);
	printf(" > Argument number: %d\n", get_arg_num(str));
	printf(" > Remaining string: %s", *str);
	while (**str != 'd')
		*str = *str + 1;
	*str = *str + 1;

//	arg = parse_arg();
	return (print_arg(arg));
}



int				ft_printf(const char *fmt, ...)
{
	size_t		count;
	va_list		ap;
	t_avlist	*av; // reserves pointers to all argument data
	char		*arg;

	count = 0;
	av = 0;
	va_start(ap, fmt);
	while ((arg = ft_strchr(fmt, '%')))
	{
		if (fmt != arg)
			count += write(1, fmt, ABS((fmt - arg)));
		count += process_arg(&arg, &ap, av);
		fmt = arg;
	}
	count += write(1, fmt, ft_strlen((char *)fmt));
//	free_arglist(arg_list);
	return (count);
}
