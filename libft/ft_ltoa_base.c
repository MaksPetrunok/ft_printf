/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:30:51 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/01 19:34:43 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Converts long int n to the string representation using selected number base.
 * Base value may be between 2 and 16. Except decimal values all other values
 * are represented as unsigned.
 * Argument 'capital' is used to select capital or small letters if base > 10.
 */

#include "libft.h"

char	*ft_ltoa_base(long int n, int base, int capital)
{
	char	*symbols;
	char	buff[65];
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
	return (ft_strdup(&buff[i + 1]));
}
