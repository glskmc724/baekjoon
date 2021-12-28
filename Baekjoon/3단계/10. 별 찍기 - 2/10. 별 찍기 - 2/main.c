#include <stdio.h>

int main(void)
{
	int max;
	scanf("%d", &max);
	for (int n = 0; n < max; n++)
	{
		for (int i = max - n - 1; i > 0; i--)
		{
			printf(" ");
		}
		for (int i = 0; i < n + 1; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}