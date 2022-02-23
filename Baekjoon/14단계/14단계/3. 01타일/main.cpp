#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000

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
			arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
		}
		return arr[n];
	}
}

int main(void)
{
	int N;
	int* arr;

	arr = (int*)malloc(sizeof(int) * MAX_NUM);

	scanf("%d", &N);

	arr[0] = 0;
	arr[1] = 1;

	printf("%d\n", (fibonacci(arr, N + 1)));

}