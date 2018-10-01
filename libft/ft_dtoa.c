/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:38:45 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/01 20:53:17 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static char	*get_float_str(double n)
{
	char	buff[65];
	int		i;

	i = 0;
	buff[i++] = '.';
	while (n != 0.0)
	{
		n = n * 10;
		buff[i++] = (int)n + '0';
		n = n - (double)(buff[i - 1] - '0');
//printf("rem %f\n", n);
	}
	buff[i] = '\0';
	return (ft_strdup(buff));
}

char	*ft_dtoa(double n)
{
	long int	integer;
	char		*s_int;
	char		*s_float;
	char		*res;

	integer = (long int)n;
	s_int = ft_ltoa_base(integer, 10, 0);
	s_float = get_float_str(n - (double)integer);
	res = ft_strjoin(s_int, s_float);
printf("%f\n", n - (double)integer);
	free((void *)s_int);
	free((void *)s_float);
	return (res);
}
