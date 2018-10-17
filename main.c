#include <stdio.h>
#include "./includes/ft_printf.h"
#include "./libft/libft.h"
#include <locale.h>

#define intmax_t long
#define uintmax_t __uintmax_t
//#define PRINT_SIZE

void	test_p(char *fmt, void *n)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, n));
	printf("\t-stdout   : %d\n", printf(fmt, n));
	printf("-----------------------------\n");
}
void	test_f(char *fmt, int n, int m)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, n, m));
	printf("\t-stdout   : %d\n", printf(fmt, n, m));
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
setlocale(LC_ALL, "");
	int ci = L'©';

//	test("%S", "Some string");
//	test("%C", ci);
	test("%#.x", 0);





return 0;
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

}
