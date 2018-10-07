#include <stdio.h>
#include <locale.h>

/*
 * printf usage:
 *
 * %[123$][#0-+ or space][min field width].[precision]
 * [length modifier (hh, h, l, ll, j, z, )][sSpdDioOuUxXcC]
 */

int		main()
{
/*
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
	printf("----------------------------\n");
*/

	setlocale(LC_NUMERIC, "");
	//printf("%'d\n\n\n", 42005);	

	printf("%5f\n", 42.006);
/*	printf("---------\n%1$d, %2$s, %2$s, %3$s\n\n", 0, "S");
//	printf("%1$d, %2$c, %2$s, %3$s\n", 0, "S", "!");
//	printf("%1$d, %2$c, %2$d, %3$s\n", 0, 378, "!");
	printf("-------------------\n");
	printf("zero padding (%%03d): %03d\n", 15);
	printf("zero padding (%%03d): %03d\n", 15342);
	printf("zero padding (%%03d): %03d\n", -15);
	printf("zero padding (%%04d): %03d\n", -15);
	printf("zero padding (%%04d): %010s\n", "STRING");
	printf("optional precision: %.5hhd\n", 155);
	printf("optional precision: %2.4f\n", 15.1);
//system("leaks a.out");
*/
//	printf("%d\n", (char)378);
	return (0);
}
