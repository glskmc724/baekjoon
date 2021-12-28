#include <stdio.h>

int main(void)
{
	int max;
	
	scanf("%d", &max);

	for (int n = 0; n < max; n++)
	{
		printf("%d\n", max - n);
	}

	return 0;
}