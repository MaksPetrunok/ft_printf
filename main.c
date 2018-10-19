#include <stdio.h>
#include "./includes/ft_printf.h"
#include "./libft/libft.h"
#include <locale.h>

#define intmax_t long
#define uintmax_t __uintmax_t
//#define PRINT_SIZE

void	test(char *fmt, int n, int m)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, n, m));
	printf("\t-stdout   : %d\n", printf(fmt, n, m));
	printf("-----------------------------\n");
}

void	test_str(char *fmt, char *s)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, s));
	printf("\t-stdout   : %d\n", printf(fmt, s));
	printf("-----------------------------\n");
}
void	test_wstr(char *fmt, wchar_t *s)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt, s));
	printf("\t-stdout   : %d\n", printf(fmt, s));
	printf("-----------------------------\n");
}
void	test_fmt(char *fmt)
{
	ft_printf("\t-ft_printf: %d\n", ft_printf(fmt));
	printf("\t-stdout   : %d\n", printf(fmt));
	printf("-----------------------------\n");
}

int main()
{
setlocale(LC_ALL, "");
	int ci = L'©';

//	test("%C", ci);
//	test_str("%5.2s is a string", "");
//	test("%#.3o", 1);
//	ft_printf("%hhldend\n", 128);
//test("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
//	test("%hhld", 128);
//	test_str("%4.15s", "42");

//	test_wstr("%S", L"我是一只猫。");

//	test_wstr("{%05.s}", L"42 c est cool");
test("%*d", 5, 42);
	//test("%f %F\n", -1.42, -1.42);
//test("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242);
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
return 0;

}
