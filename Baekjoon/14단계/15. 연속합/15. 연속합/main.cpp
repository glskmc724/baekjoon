#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a: b

int main(void)
{
	int num;
	int* arr;
	int* dp;
	int result;

	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * (num + 1));
	dp = (int*)malloc(sizeof(int) * (num + 1));

	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &arr[i]);
	}

	arr[0] = dp[0] = 0;

	for (int i = 1; i <= num; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}
	/*
	for (int i = 1; i <= num; i++)
	{
		printf("%3d ", arr[i]);
	}
	printf("\n");
	for (int i = 1; i <= num; i++)
	{
		printf("%3d ", dp[i]);
	}
	printf("\n");
	*/
	result = -1001;
	for (int i = 1; i <= num; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
	}
	printf("%d\n", result);
}