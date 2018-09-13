#include <stdio.h>

/*
 * printf usage:
 *
 * %[123$][#0-+ or space][min field width].[precision]
 * [length modifier (hh, h, l, ll, j, z, )][sSpdDioOuUxXcC]
 */

int		main()
{
	printf("%ld\n", "s");

	printf("%%\n");
// $ - for bonus part only
	printf("%1$d\n", 42);
	printf("%2$d\n", 42);
	printf("%3$d\n", 42, 21, 10);
	printf("i = %d, and k = %1$d as well. But m = %d and n = %2$d\n", 42, 88);
// o - octal
	printf("--- octal ---\n");
	printf("%o\n", 0);
	printf("%o\n", 9);
	printf("%#o\n", 9);	

	printf("--- hex ---\n");
	printf("%x\n", 0);
	printf("%x\n", 16);
	printf("%#x\n", 16);	


	printf("%1$hhwd\n", 42);
	return (0);
}
