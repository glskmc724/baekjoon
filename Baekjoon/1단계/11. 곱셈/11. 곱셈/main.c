#include <stdio.h>

int main(void)
{
	unsigned int A, B;

	scanf("%d %d", &A, &B);

	if (A < 1000 && B < 1000)
	{
		printf("%d\n", A * (B % 10));
		printf("%d\n", (A * ((B % 100) - (B % 10)) / 10));
		printf("%d\n", A * (B / 100));
		printf("%d\n", A * B);
	}

	return 0;
}