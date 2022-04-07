#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a < b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main(void)
{
	int num;
	int* wine;
	int* dp;
	int result;

	scanf("%d", &num);
	wine = (int*)malloc(sizeof(int) * num);
	dp = (int*)malloc(sizeof(int) * (num + 1));

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &wine[i]);
	}

	dp[0] = 0;
	dp[1] = wine[0];
	dp[2] = wine[0] + wine[1];
	for (int i = 3; i <= num; i++)
	{
		dp[i] = max((wine[i - 1] + max(dp[i - 3] + wine[i - 2], dp[i - 2])), dp[i - 1]);
	}

	//printf("\n");
	result = 0;
	for (int i = 0; i <= num; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
		//printf("%d\n", dp[i]);
	}
	printf("%d\n", result);
}
