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
	int N;
	int* arr;
	int count;
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
		{
			break;
		}
		arr = (int*)malloc(sizeof(int) * (2 * N + 1));
		eratostenes(arr, N * 2);
		count = 0;
		for (int i = N + 1; i <= N * 2; i++)
		{
			if (arr[i] != 0)
			{
				count += 1;
				//printf("%d\n", arr[i]);
			}
		}
		printf("%d\n", count);
	}
}