#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
	if (n == 1)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int M, N;
	int sum;
	int min;

	scanf("%d %d", &M, &N);
	sum = 0;
	min = 12345;
	for (int i = M; i <= N; i++)
	{
		if (is_prime(i) == 1)
		{
			sum += i;
			if (min > i)
			{
				min = i;
			}
		}
	}
	if (min == 12345)
	{
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", sum);
		printf("%d\n", min);
	}

}