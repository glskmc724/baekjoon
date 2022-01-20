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
	int M, N;
	int* arr;
	scanf("%d %d", &M, &N);
	arr = (int*)malloc(sizeof(int) * (N + 1));
	eratostenes(arr, N);
	for (int i = M; i <= N; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d\n", arr[i]);
		}
	}
}