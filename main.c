int	ft_printf(const char *fmt, ...);
#include <stdio.h>

int main(int ac, char **av)
{
//	printf("\t\t- %d\n", ft_printf("Simple string."));
ft_printf("Before\n %#+00-+0 '8d\n", 42);
//ft_printf("No number %d\n", 24);
//ft_printf("Complex %d, %-3$d\n", 12, 24, 42);
	/*
	ft_printf("String with %% symbol\n");
	ft_printf("String with %s string\n", "INSIDE");
	ft_printf("decimal int here: %d\n", 999);
	ft_printf("octal   int here: %o\n", 999);
	ft_printf("small   hex here: %x\n", 999);
	ft_printf("capital hex here: %X\n", 999);
	ft_printf("binary:     here: %b\n", 999);
	ft_printf("double:   %f\n", 999.999);
*/
	return (0);
}
