#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define max(a, b) a > b ? a : b

int main(void)
{
	char arr1[MAX_LENGTH + 1] = { 0 };
	char arr2[MAX_LENGTH + 1] = { 0 };
	int** dp;
	int len;
	int result;

	arr1[0] = arr2[0] = 0;
	scanf("%s", arr1 + 1);
	scanf("%s", arr2 + 1);
	len = max(strlen(arr1 + 1), strlen(arr2 + 1));
	dp = (int**)malloc(sizeof(int*) * (len + 1));
	for (int i = 0; i <= len; i++)
	{
		dp[i] = (int*)malloc(sizeof(int) * (len + 1));
	}
	for (int i = 0; i < len + 1; i++)
	{
		for (int j = 0; j < len + 1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (arr1[i] == arr2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	/*
	printf("%3c ", ' ');
	for (int i = 1; i <= len; i++)
	{
		printf("%3c ", arr1[i]);
	}
	printf("\n");
	for (int i = 1; i <= len; i++)
	{
		printf("%3c ", arr2[i]);
		for (int j = 1; j <= len; j++)
		{
			printf("%3d ", dp[i][j]);
		}
		printf("\n");
	}
	*/
	result = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (result < dp[i][j])
			{
				result = dp[i][j];
			}
		}
	}
	printf("%d\n", result);
}