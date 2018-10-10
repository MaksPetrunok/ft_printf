/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:32:12 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/10 15:47:08 by mpetruno         ###   ########.fr       */
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
	if (arg->lengthmod > 0)
		*str += (arg->lengthmod > 2) ? 1 : 2;
	arg->type = **str;
	*str = *str + 1;
	if (ft_strchr("DOUCS", arg->type) != 0)
	{
		arg->type = ft_tolower(arg->type);
		arg->lengthmod = MAX(arg->lengthmod, l);
	}
}

void		parse_flags(char **str, t_fmarg *arg)
{
	char	*tmp;
	char	*fl;
	int		i;

	fl = FLAGS;
	i = 0;
	while ((tmp = ft_strchr(fl, **str)) != 0)
	{
		if (ft_strchr(arg->flags, **str) == 0)
			arg->flags[i++] = **str;
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
