#include <stdio.h>

int cmp_std(char *s1, char *s2)
{
	while (s1 != s2)
		s1++;
	return (s1 == s2);
}


int cmp_bit(char *s1, char *s2)
{
	while (s1 ^ s2)
		s1++;
	return (s1 == s2);
}

#define SIZE 1000000

int main()
{
	char buff[SIZE + 1];
	int	n = 10;

	for (int i=0; i<n; i++)
		printf("%d", cmp_std(buff, buff + SIZE));
	printf("\n");
	for (int i=0; i<n; i++)
		printf("%d", cmp_bit(buff, buff + SIZE));
	printf("\n");
	return (0);
}
