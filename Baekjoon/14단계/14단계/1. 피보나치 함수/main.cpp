#include <stdio.h>
#include <stdlib.h>

int fibonacci(int* arr, int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else 
	{
		for (int i = 2; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n];
	}
}

int main(void)
{
	int T, N;
	int* arr;
	int result;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		arr = (int*)malloc(sizeof(int) * (N + 1));
		arr[0] = 0;
		arr[1] = 1;
		result = fibonacci(arr, N);
		if (N == 0)
		{
			printf("%d %d\n", 1, 0);
		}
		else if (N == 1)
		{
			printf("%d %d\n", 0, 1);
		}
		else
		{
			printf("%d %d\n", fibonacci(arr, N - 1), result);
		}
	}
}