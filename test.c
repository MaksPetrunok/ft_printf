#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <locale.h>

#include "ft_printf/includes/ft_printf.h"

int main()
{
	wchar_t c = L'©';
	unsigned char u[4];
	int	len;


	c = 255;

	len = 0;
	u[0] = u[1] = 0;
	if (c >=0 && c <= 0x7F)
	{
		u[0] = (char)c;
		len = 1;
	}
	else if (c >= 0x80 && c <= 0xFF)
	{
		u[0] = 128+64 | (c >> 6);
		u[1] = 128 | c - ((c >> 6) << 6);
		len = 2;
	}
	write(1, u, len);
	
	ft_printf("\nsrc:	%b\n1:	%b\n2:	%b\n", c, u[0], u[1]);


setlocale(LC_ALL, "");
	printf("\nprintf: %C\n", c);



	return (0);
}
