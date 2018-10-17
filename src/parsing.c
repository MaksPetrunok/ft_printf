/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:32:12 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/17 15:30:25 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // REMOVE ME

static char	parse_length(char **str, t_fmarg *arg)
{
	if (**str == 'h')
		arg->flags |= (*(*str + 1) == 'h') ? F_CHAR : F_SHORT;
	else if (**str == 'l')
		arg->flags |= (*(*str + 1) == 'l') ? F_LLONG : F_LONG;
	else if (**str == 'j')
		arg->flags |= F_INTMAX;
	else if (**str == 'z')
		arg->flags |= F_SIZE_T;
	else
		return (0);
	*str += ((arg->flags & (F_CHAR | F_LLONG)) > 0) * 2 +
		((arg->flags & (F_SHORT | F_LONG | F_INTMAX | F_SIZE_T)) > 0);
	return (1);
}

static char	parse_type(char **str, t_fmarg *arg)
{
	if (**str == '\0' || ft_strchr(TYPES, **str) == 0)
		return 0;
	else
		arg->type = **str;
	*str = *str + 1;
	if (ft_strchr("DOUCS", arg->type) != 0)
	{
		arg->type = ft_tolower(arg->type);
		arg->flags |= F_LONG;
	}
	if (arg->type == 'p')
		arg->flags |= F_HASH | F_LLONG;
	return (1);
}

static char	parse_num(char **s, int *n)
{
	*n = ft_atoi(*s);
	while (**s >= '0' && **s <= '9')
		(*s)++;
	return (1);
}

static char	parse_fl(char **s, t_fmarg *arg)
{
	if (**s == '#')
		arg->flags |= F_HASH;
	else if (**s == '0')
		arg->flags |= F_ZERO;
	else if (**s == '-')
		arg->flags |= F_LEFT;
	else if (**s == ' ')
		arg->flags |= F_SPACE;
	else if (**s == '+')
		arg->flags |= F_PLUS;
	else if (**s == '\'')
		arg->flags |= F_THOU;
	else
		return (0);
	if ((**s == '0' || **s == '-') && *(*s + 1) >= '0' && *(*s + 1) <= '9')
	{
		*s = *s + 1;
		parse_num(s, &(arg->width));
	}
	else
		(*s)++;
	return (1);
}

void				parse_flags(char **str, t_fmarg *arg)
{
	char	*fl;
	char	cont;

	fl = FLAGS;
	cont = 1;
	while (**str && arg->type == 0)
	{
		cont = 0;
		if (**str == '.')
		{
			arg->flags |= F_PREC;
			*str = *str + 1;
			cont = parse_num(str, &(arg->precision));
		}
		else if (**str >= '1' && **str <= '9')
			cont = parse_num(str, &(arg->width));
		else if (ft_strchr(fl, **str) != 0)
			cont = parse_fl(str, arg);
		else
			cont = parse_length(str, arg);
		if (parse_type(str, arg) || !cont)
			break ;
	}
}
