#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	printf("char		%ld\n", sizeof(char));
	printf("short		%ld\n", sizeof(short));
	printf("int		%ld\n", sizeof(int));
	printf("long		%ld\n", sizeof(long));
	printf("long long	%ld\n", sizeof(long long));
	printf("intmax_t	%ld\n", sizeof(intmax_t));
	printf("uintmax_t	%ld\n", sizeof(uintmax_t));
	printf("size_t		%ld\n", sizeof(size_t));
printf("\n\n");

	ft_printf(" = %d\n", ft_printf("0 padding: %+08d, -width: %-8d.", 42, 42));

printf("========= by standard printf:\n");
	printf(" = %d\n", printf("0 padding: %+08d, -width: %-8d.", 42, 42));
//	printf("\t\t- %d\n", ft_printf("Simple string."));
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
