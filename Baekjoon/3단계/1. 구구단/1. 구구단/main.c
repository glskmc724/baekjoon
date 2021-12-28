#include <stdio.h>

int main(void)
{
	int input;

	scanf("%d", &input);

	for (int n = 1; n < 10; n++)
	{
		printf("%d * %d = %d\n", input, n, input * n);
	}

	return 0;
}