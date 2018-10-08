/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:34:39 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/08 15:38:49 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	print_arg(t_fmarg *arg, va_list *ap)
{
	char	*fl;
	int		i;

	if (ap == 0)
		ap = 0;
	i = 0;
	fl = FLAGS;

printf("flags = %d\n", arg->flags);
	if (arg->flags > 0)
		printf("parsed flags: ");
	else
		printf("No flags found\n");

	while (arg->flags > 0)
	{
		if ((arg->flags & 1) == 1)
			printf("%c", *(fl + i));
		arg->flags = arg->flags >> 1;
//printf(">>>>> %d\n", arg->flags);
		i++;
	}
	printf("\n");
	return (0);
}
