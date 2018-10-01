#include <stdio.h>
#include "libft.h"

int	main()
{
	long int x = 1000000000000;
	long int y = 100000000000;

	while (y > 0 && x > 0)
	{
		while (x + y > 0)
			x += y;
		y /= 10;
	}
/*	
	printf("x = %ld\n", x);

	printf("-------------------------------\n");
	printf("%s\n", ft_ltoa_base(127, 10, 1));
	printf("%s\n", ft_ltoa_base(-129, 10, 1));
	printf("%s\n", ft_ltoa_base(255, 16, 1));
	printf("%s\n", ft_ltoa_base(255, 16, 0));
	printf("%s\n", ft_ltoa_base(256, 16, 0));
	printf("%s\n", ft_ltoa_base(15, 2, 0));
	printf("%s\n", ft_ltoa_base(255, 2, 0));
	printf("%s\n", ft_ltoa_base(-1, 2, 0));
	printf("%s\n", ft_ltoa_base(15, 8, 0));
	printf("%s\n", ft_ltoa_base(16, 8, 0));

	printf("%s\n", ft_ltoa_base(9223372036854775807, 10, 1));
	printf("%s\n", ft_ltoa_base(-9223372036854775808, 10, 1));


	printf("%s\n", ft_ltoa_base(-128, 2, 1));
	printf("%s\n", ft_ltoa_base(127, 2, 1));
	printf("%s\n", ft_ltoa_base(-9223372036854775808, 2, 1));
	printf("%s\n", ft_ltoa_base(9223372036854775807, 2, 1));
	printf("%s\n", ft_ltoa_base(0, 2, 1));

	printf("-------- ft_ultoa_base --------------\n");

	printf("%s\n", ft_ultoa_base(-128, 2, 1));
	printf("%s\n", ft_ultoa_base(127, 2, 1));
	printf("%s\n", ft_ultoa_base(255, 2, 1));
	printf("%s\n", ft_ultoa_base(-9223372036854775808, 2, 1));
	printf("%s\n", ft_ultoa_base(9223372036854775807, 2, 1));
	printf("%s\n", ft_ultoa_base(18446744073709551615, 2, 1));
	printf("%s\n", ft_ultoa_base(0, 2, 1));

*/
	printf("-------- ft_dtoa ----------\n");
	printf("%s\n", ft_dtoa(0.895, 20));
	printf("%s\n", ft_dtoa(25.0, 20));
	printf("%s\n", ft_dtoa(29.895, 6));
	printf("%.6f\n", 29.895);

//	system("leaks a.out");
	return (0);
}
