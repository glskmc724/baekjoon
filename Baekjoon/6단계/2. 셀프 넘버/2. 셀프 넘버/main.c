#include <stdio.h>
#include <stdlib.h>

int d(int n) // n = 33, 33 + 3 + 3 = 39
{
	int sum;
	sum = 0;
	for (int i = n; i > 0; i = i / 10)
	{
		sum = sum + (i % 10);
	}
	return n + sum;
}

int is_construct(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (d(i) == n)
		{
			return 1;
		}
	}
	return 0;
}

int main(void) 
{
	for (int i = 1; i <= 10000; i++)
	{
		if (is_construct(i) != 1)
		{
			printf("%d\n", i);
		}
	}
}