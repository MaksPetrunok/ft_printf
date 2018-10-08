/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:32:12 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/08 16:17:23 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_length(char **str, t_fmarg *arg)
{
	int		i;

	i = 0;
	while (ft_strchr(TYPES, **str) == 0)
		arg->lengthmod[i++] = *(*str)++;
	arg->lengthmod[i] = '\0';
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
		if ((**str == '0' || **str == '-') &&
			(arg->width = ft_atoi(++(*str))) > 0)
			while (**str >= '0' && **str <= '9')
				(*str)++;
		else
			(*str)++;
	}
	if (**str == '.')
		arg->precision = ft_atoi(++(*str));
	while (**str >= '0' && **str <= '9')
		(*str)++;
	parse_length(str, arg);
}
