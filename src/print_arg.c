/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/10 19:00:41 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	arg_to_str_s(t_fmarg *arg, va_list *ap, char **str)
{
	if (arg->type == 's' && arg->lengthmod == 0)
		*str = (char *)va_arg(*ap, char *);
	if (arg->type == 'c' && arg->lengthmod == 0)
		*str = va_arg(*ap, char *);
//	printf("!!!!!!!!!!!!! HERE !!!!!!!!!\n");
//	printf("%s\n", *str)
}

static int	print_prefix(t_fmarg *a, char *s, int len)
{
	if (ft_strchr("di", a->type))
		return (print_di(a, s, len));
	else if (ft_strchr("o", a->type))
		return (print_o(a, s, len));
	else if (ft_strchr("fF", a->type))
		return (print_f(a, s, len));
	else if (ft_strchr("xX", a->type))
		return (print_x(a, s, len));
	else if (ft_strchr("ubs%", a->type))
		return (print_u(a, s, len));
//	else if (ft_strchr("cC%", arg->type))
//		return (printf_pr_c(a, s, len));
	return (0);
}

int			print_arg(t_fmarg *arg, va_list *ap)
{
	char	*str;
	char	buff[65];
	int		count;
	int		len;

	count = 0;
	if (ft_strchr("sScC", arg->type))
		arg_to_str_s(arg, ap, &str);
	else if (ft_strchr("di", arg->type))
		arg_to_str_di(arg, ap, (str = buff));
	else if (ft_strchr("ouxXb", arg->type))
		arg_to_str_ouxX(arg, ap, str = buff);
	else if (ft_strchr("fF", arg->type))
		arg_to_str_f(arg, ap, (str = buff));
	else
		str = "%";
	len = ft_strlen(str);
	count += print_prefix(arg, str, len);
//	count += write(1, str, len);
//	count += print_suffix();
	return (count);
}
