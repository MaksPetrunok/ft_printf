
#include "ft_printf.h"
#include <stdio.h> // remove me

void	print_c(t_fmarg *a, char *s, int len, t_outbuff *buffer)
{
	char	fill;
	int		n;

	fill = (a->flags & F_ZERO) ? '0' : ' ';
	if (!(a->flags & F_LEFT) && (n = (a->width - (MAX(a->precision, len)))) > 0)
		appendchr(buffer, (a->precision < 0) ? fill : ' ', n);
	if ((n = (a->precision - len)) > 0)
		appendchr(buffer, '0', n);
	append(buffer, s, len);
	if (a->flags & F_LEFT && (n = (a->width - (MAX(a->precision, len)))) > 0)
		appendchr(buffer, ' ', n);
}
