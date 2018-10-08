/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:32:12 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/08 19:49:04 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // REMOVE ME

static void	parse_length(char **str, t_fmarg *arg)
{
	if (ft_strncmp(*str, "hh", 2) == 0)
		arg->lengthmod = hh;
	else if (ft_strncmp(*str, "ll", 2) == 0)
		arg->lengthmod = ll;
	else if (**str == 'h')
		arg->lengthmod = h;
	else if (**str == 'l')
		arg->lengthmod = l;
	else if (**str == 'j')
		arg->lengthmod = j;
	else if (**str == 'z')
		arg->lengthmod = z;
	if (arg->lengthmod)
		*str += (arg->lengthmod > 2) ? 1 : 2;
	arg->type = *(*str)++;
}

void		parse_flags(char **str, t_fmarg *arg)
{
	char	*tmp;
	char	*fl;

	fl = FLAGS;
	while ((tmp = ft_strchr(fl, **str)) != 0)
	{
		arg->flags = arg->flags | (1 << (int)(ABS((tmp - fl))));
		if (**str == '0' || **str == '-')
		{
			arg->width = ft_atoi(++(*str));
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else
			(*str)++;
	}
	if (**str == '.')
		arg->precision = ft_atoi(++(*str));
	while (**str >= '0' && **str <= '9')
		(*str)++;
	parse_length(str, arg);
}
