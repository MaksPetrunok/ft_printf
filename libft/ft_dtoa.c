/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:38:45 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/19 19:47:52 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h> //remove me
static int	get_float_str(double n, char *buff, int precision)
{
	int		i;

	i = 0;
	n = (n < 0) ? -n : n;
	buff[i++] = (precision == 0) ? '\0' : '.';
	while (precision > 0)
	{
		n = n * 10;
		buff[i++] = (int)n + '0';
		n = n - (double)(buff[i - 1] - '0');
		precision--;
	}
	buff[i--] = '\0';
	while (i > 0 && n * 10 > 4)
	{
		buff[i] += (buff[i + 1] == '\0') ? 1 : 0;
		if (buff[i + 1] == '9' + 1)
		{
			buff[i]++;
			buff[i + 1] = '0';
		}
		i--;
	}
	if (buff[1] == '9' + 1)
		return ((buff[1] = '0') == '0');
	return (0);
}

void		ft_dtoa(double n, int precision, char *buff)
{
	long int	integer;
	char		s_int[65];
	char		s_float[65];
	char		*res;

	precision = (precision < 0) ? 0 : precision;
	integer = (long int)n;
//printf("PASSED ARG = %f\n", n);
	if (get_float_str(n - (double)integer, s_float, precision))
		integer++;
	ft_lltoa_base(integer, 10, 0, s_int);
	res = ft_strjoin(s_int, s_float);
//printf("INSIDE DTOA\n");
	//s_float = res;
//printf("RESULT FLOAT = %s\n", res);
//printf("INT NUM = %ld\n", integer);
//printf("INT   = %s\n", s_int);
//printf("FLOAT = %s\n", s_float);
	ft_strcpy(buff, res); // replace with no heap usage, only stack
//	while (res)
//		*buff++ = *res++;
//	*buff = '\0';
//printf("RESULT FLOAT = %s\n", buff);
	free((void *)res);
//	return (res);
}
