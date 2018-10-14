/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:32:12 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/12 19:14:46 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // REMOVE ME

static inline void	parse_length(char **str, t_fmarg *arg)
{
	if (**str == 'h')
		arg->flags |= (*(*str + 1) == 'h') ? F_CHAR : F_SHORT;
	else if (**str == 'l')
		arg->flags |= (*(*str + 1) == 'l') ? F_LLONG : F_LONG;
	else if (**str == 'j')
		arg->flags |= F_INTMAX;
	else if (**str == 'z')
		arg->flags |= F_SIZE_T;
	*str += ((arg->flags & (F_CHAR | F_LLONG)) > 0) * 2 +
		((arg->flags & (F_SHORT | F_LONG | F_INTMAX | F_SIZE_T)) > 0);

	arg->type = **str;
	*str = *str + 1;
	if (ft_strchr("DOUCS", arg->type) != 0)
	{
		arg->type = ft_tolower(arg->type);
		arg->flags |= F_LONG;
	}
	if (arg->type == 'p')
	{
		arg->type = 'x';
		arg->flags |= F_HASH | F_LLONG;
	}
}

static inline void	parse_w(char **s, t_fmarg *arg)
{
	arg->width = ft_atoi(*s);
	while (**s >= '0' && **s <= '9')
		(*s)++;
}

static inline void	parse_p(char **s, t_fmarg *arg)
{
	arg->precision = ft_atoi(*s);
	while (**s >= '0' && **s <= '9')
		(*s)++;
}

static inline void	parse_fl(char **s, t_fmarg *arg)
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
	if ((**s == '0' || **s == '-') && *(*s + 1) >= '0' && *(*s + 1) <= '9')
	{
		*s = *s + 1;
		parse_w(s, arg);
	}
	else
		(*s)++;
}

void				parse_flags(char **str, t_fmarg *arg)
{
	char	*tmp;
	char	*fl;

	fl = FLAGS;
	while ((tmp = ft_strchr(fl, **str)) != 0 ||
		(**str >= '0' && **str <= '9') ||
		**str == '.')
	{
		if (**str == '.')
		{
			arg->flags |= F_PREC;
			*str = *str + 1;
			parse_p((str), arg);
		}
		else if (**str >= '1' && **str <= '9')
			parse_w(str, arg);
		else
			parse_fl(str, arg);
	}
	parse_length(str, arg);
}
