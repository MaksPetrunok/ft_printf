#include <stdio.h>
#include "./includes/ft_printf.h"
#include "./libft/libft.h"

#define intmax_t long
#define uintmax_t __uintmax_t
//#define PRINT_SIZE

void	test_p(char *fmt, void *n)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, n));
	printf("\t-stdout   : %d\n", printf(fmt, n));
	printf("-----------------------------\n");
}
void	test_f(char *fmt, double n)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, n));
	printf("\t-stdout   : %d\n", printf(fmt, n));
	printf("-----------------------------\n");
}
void	test(char *fmt, int n)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, n));
	printf("\t-stdout   : %d\n", printf(fmt, n));
	printf("-----------------------------\n");
}

int main()
{
	int c = L'©';
	char	cc = *(char *)(&c);
	ft_printf("%b\n", c << 8);
	return (0);

	printf("MULTI BYTE: %d\n", MB_CUR_MAX);
	/*
	t_outbuff out;

	initialize_output_buff(&out, 1);
	
	out.append(&out, "string1", 0);
	flush(&out);
	out.append(&out, "STring2", 2);
	out.flush(&out);
	printf("\nWritten bytes: %d\n", out.count);
*/

//	test("%04u", 42);
//	test("%+ d", 42);
	char *s = "234";
//	test_f("%f", 0.0);
	test_p("%-20.15p", s);
return 0;


	return 0;

	ft_printf("THOUSANDS TEST: %#'u\n", 42000);
	ft_printf("STRING BEFORE ARGUMENT %llX\n", 4294967296);

	ft_printf(" = %d\n", ft_printf("0 padding: %+08d, -width: %-8d.", 42, 42));
	ft_printf(" = %d\n", ft_printf("0 padding: %+8o, -width: %#-8o.", 42, 42));
	ft_printf(" = %d\n", ft_printf("0 padding: %+08x, -width: %#-8x.", 42, 42));
	ft_printf(" = %d\n", ft_printf("0 padding: %+8X, -width: %#-8X.", 42, 42));
	ft_printf(" = %d\n", ft_printf("0 padding: %+8u, -width: %#-8u.", -42, 42));
	ft_printf(" = %d\n", ft_printf("0 padding: %8%, str=%s.", "42str"));
	ft_printf(" = %d\n", ft_printf("0 padding: %08b.", 9));
	ft_printf(" = %d\n", ft_printf("float    : %#+05.0f.", 42.0));

printf("========= by standard printf:\n");
	printf(" = %d\n", printf("0 padding: %+08d, -width: %-8d.", 42, 42));
	printf(" = %d\n", printf("0 padding: %+8o, -width: %#-8o.", 42, 42));
	printf(" = %d\n", printf("0 padding: %+08x, -width: %#-8x.", 42, 42));
	printf(" = %d\n", printf("0 padding: %+8X, -width: %#-8X.", 42, 42));
	printf(" = %d\n", printf("0 padding: %+8u, -width: %#-8u.", -42, 42));
	printf(" = %d\n", printf("0 padding: %8%, str=%s.", "42str"));
	printf(" = %d\n", printf("float    : %#+05.0f.", 42.0));
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

#ifdef PRINT_SIZES
printf("\n\n");
	printf("char		%ld\n", sizeof(char));
	printf("short		%ld\n", sizeof(short));
	printf("int		%ld\n", sizeof(int));
	printf("long		%ld\n", sizeof(long));
	printf("long long	%ld\n", sizeof(long long));
	printf("intmax_t	%ld\n", sizeof(intmax_t));
	printf("uintmax_t	%ld\n", sizeof(uintmax_t));
	printf("size_t		%ld\n", sizeof(size_t));
#endif
	return (0);
}
