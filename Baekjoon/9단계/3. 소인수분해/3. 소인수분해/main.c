#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	for (int i = 2; num != 1; i++)
	{
		if (num % i == 0)
		{
			printf("%d\n", i);
			num /= i;
			i -= 1;
		}
	}
}