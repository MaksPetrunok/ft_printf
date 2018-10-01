/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:30:51 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/01 19:37:03 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Converts unsigned long n to the string representation using selected number
 * base. Base value may be between 2 and 16.
 * Argument 'capital' is used to select capital or small letters if base > 10.
 */

#include "libft.h"

char	*ft_ultoa_base(unsigned long int n, int base, int capital)
{
	char	*symbols;
	char	buff[65];
	int		i;

	i = 64;
	buff[i--] = '\0';
	if (n == 0)
		buff[i--] = '0';
	symbols = (capital) ? "0123456789ABCDEF" : "0123456789abcdefgh";
	while (n != 0)
	{
		buff[i--] = symbols[n % base];
		n /= base;
	}
	return (ft_strdup(&buff[i + 1]));
}

