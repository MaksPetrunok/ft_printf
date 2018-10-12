/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:37:56 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/12 18:03:38 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //remove

void	flush(t_outbuff *buff)
{
	buff->count += write(buff->fd, buff->buffer, buff->end - buff->buffer);
	buff->end = buff->buffer;
}

/*
 * If n = -1 all string *str should be appended to buffer.
 * Otherwise n symbols from *str appended.
 */

void	append(t_outbuff *buff, const char *str, int n)
{
	while ((buff->end - buff->buffer) < OUTPUT_BUFF_SIZE && *str && n != 0)
	{
		*(buff->end++) = *str++;
		n--;
	}
	if (*str && n != 0)
	{
		flush(buff);
		append(buff, str, n);
	}
}

void	initialize_output_buff(t_outbuff *buff, int fd)
{
	buff->fd = fd;
	buff->count = 0;
	buff->buffer[0] = '\0';
	buff->end = buff->buffer;
	buff->flush = &flush;
	buff->append = &append;
}
