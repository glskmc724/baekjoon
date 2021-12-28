#include <stdio.h>

int main(void)
{
	int max, acc;
	
	scanf("%d", &max);

	acc = 0;
	for (int n = 0; n < max; n++)
	{
		acc += (n + 1);
	}
	printf("%d", acc);
}