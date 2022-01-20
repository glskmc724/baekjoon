#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eratostenes(int* arr, int n)
{
	int prime;

	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (arr[i] != 0)
		{
			for (int j = i * 2; j <= n; j += i)
			{
				arr[j] = 0;
			}
		}
	}
}

int main(void)
{
	int loop, N;
	int* arr;
	int A, B, diff, min;
	scanf("%d", &loop);
	for (int count = 0; count < loop; count++)
	{
		scanf("%d", &N);
		arr = (int*)malloc(sizeof(int) * (N + 1));
		eratostenes(arr, N);
		min = 10000;
		for (int i = 0; i <= (N / 2); i++)
		{
			A = N / 2 - i;
			B = N / 2 + i;

			if (arr[A] != 0 && arr[B] != 0)
			{
				diff = B - A;
				if (diff < min)
				{
					min = diff;
					printf("%d %d\n", A, B);
				}
			}
		}
	}
}