/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:51:12 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/12 19:10:40 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ulltoa_base(unsigned long long int n, int base, t_fmarg *fm, char *b)
{
	char	*symbols;
	char	buff[NTOA_BUFF_SIZE];
	int		i;
	int		t;

	t = 1;
	i = NTOA_BUFF_SIZE - 1;
	buff[i--] = '\0';
	if (n == 0)
		buff[i--] = '0';
	symbols = (fm->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdefgh";
	while (n != 0)
	{
		buff[i--] = symbols[n % base];
		n /= base;
		if (base == 10 && fm->flags & F_THOU && (t++ % 3) == 0)
			buff[i--] = ' ';
	}
	i++;
	while (buff[i])
		*b++ = buff[i++];
	*b = '\0';
}
/*
void	pf_lltoa_base(long long int n, int base, t_rmarg *fm, char *new_buff)
{
	char	*symbols;
	char	buff[NTOA_BUFF_SIZE];
	int		i;
	char	negative;
	int		index;

	i = 64;
	buff[i--] = '\0';
	if (n == 0)
		buff[i--] = '0';
	symbols = (capital) ? "0123456789ABCDEF" : "0123456789abcdefgh";
	negative = (base == 10 && n < 0);
	while (n != 0)
	{
		index = n % base;
		buff[i--] = symbols[(index < 0) ? -index : index];
		n /= base;
	}
	if (negative)
		buff[i--] = '-';
	index = 0;
	while (buff[++i])
		new_buff[index++] = buff[i];
	new_buff[index] = 0;
}

static int	get_float_str(double n, char *buff, int precision)
{
	int		i;

	i = 0;
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

void		ft_dtoa(double n, t_fmarg *fm, char *buff)
{
	long int	integer;
	char		s_int[NTOA_BUFF_SIZE];
	char		s_float[NTOA_BUFF_SIZE];
	char		*res;

	precision = (precision < 0) ? 0 : precision;
	integer = (long int)(int)n;
	if (get_float_str(n - (double)integer, s_float, precision))
		integer++;
	ft_lltoa_base(integer, 10, 0, s_int);
	res = ft_strjoin(s_int, s_float);
	ft_strcpy(buff, res);
	free((void *)res);
}
*/
