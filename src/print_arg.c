/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/12 18:15:57 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
static void	arg_to_str_s(t_fmarg *arg, va_list *ap, char **str)
{
	if (arg->type == 's' && arg->lengthmod == 0)
		*str = (char *)va_arg(*ap, char *);
	if (arg->type == 'c' && arg->lengthmod == 0)
		*str = va_arg(*ap, char *);
//	printf("!!!!!!!!!!!!! HERE !!!!!!!!!\n");
//	printf("%s\n", *str)
}
*/

static void	print_prefix(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	if (ft_strchr("di", a->type))
		print_di(a, s, len, buffer);
	else if (ft_strchr("o", a->type))
		print_o(a, s, len, buffer);
	else if (ft_strchr("fF", a->type))
		print_f(a, s, len, buffer);
	else if (ft_strchr("xX", a->type))
		print_x(a, s, len, buffer);
	else if (ft_strchr("ubs%", a->type))
		print_u(a, s, len, buffer);
//	else if (ft_strchr("cC%", a->type))
//		return (printf_pr_c(a, s, len));
}

void		print_arg(t_fmarg *arg, va_list *ap, t_outbuff *buffer)
{
	char	*str;
	char	buff[NTOA_BUFF_SIZE];
	int		len;

//	if (ft_strchr("sScC", arg->type))
//		arg_to_str_s(arg, ap, &str);
	if (ft_strchr("di", arg->type))
		arg_to_str_di(arg, ap, (str = buff));
	else if (ft_strchr("ouxXb", arg->type))
		arg_to_str_ouxX(arg, ap, str = buff);
	else if (ft_strchr("fF", arg->type))
		arg_to_str_f(arg, ap, (str = buff));
	else
		str = "%";
	len = ft_strlen(str);
	print_prefix(arg, str, len, buffer);
//	count += write(1, str, len);
//	count += print_suffix();
}
