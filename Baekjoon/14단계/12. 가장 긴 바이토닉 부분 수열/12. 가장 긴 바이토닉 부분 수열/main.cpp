#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

/*
10
1 5 2 1 4 3 4 5 2 1
*/

int main(void)
{
	int len;
	int* arr;
	int* dp1;
	int* dp2;
	int idx, last_value;
	int result;

	scanf("%d", &len);
	arr = (int*)malloc(sizeof(int) * (len + 1));
	dp1 = (int*)malloc(sizeof(int) * (len + 1));
	dp2 = (int*)malloc(sizeof(int) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i + 1]);
	}

	for (int i = 0; i <= len; i++)
	{
		dp1[i] = dp2[i]  = 0;
	}

	arr[0] = dp1[0] = dp2[0] = 0;
	idx = 0;
	for (int i = 1; i <= len; i++)
	{
		last_value = 0;
		for (int j = 0; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				//printf("last: %d, arr[i=%d]: %d > arr[j=%d]: %d\n", last_value, i, arr[i], j, arr[j]);
				last_value = max(last_value, dp1[j]);
			}
		}
		dp1[i] = last_value + 1;
		/*
		printf("idx: %d\n", idx);
		printf("dp: %d\n", dp1[i]);

		printf("i: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", i);
		}
		printf("\nA: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", arr[i]);
		}
		printf("\nD: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", dp1[i]);
		}
		printf("\n\n");
		*/
	}

	for (int i = len; i >= 1; i--)
	{
		last_value = 0;
		for (int j = len; j >= 1; j--)
		{
			if (arr[i] > arr[j])
			{
				//printf("last: %d, arr[i=%d]: %d > arr[j=%d]: %d\n", last_value, i, arr[i], j, arr[j]);
				last_value = max(last_value, dp2[j]);
			}
		}
		dp2[i] = last_value + 1;
		/*
		printf("idx: %d\n", idx);
		printf("dp: %d\n", dp2[i]);

		printf("i: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", i);
		}
		printf("\nA: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", arr[i]);
		}
		printf("\nD: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", dp2[i]);
		}
		printf("\n\n");
		*/
	}

	
	result = 0;
	for (int i = 1; i <= len; i++)
	{
		if (result < dp1[i] + dp2[i] - 1)
		{
			result = dp1[i] + dp2[i] - 1;
		}
		//printf("%d\n", dp[i]);
	}
	printf("%d\n", result);
	
	/*
	printf(" i: ");
	for (int i = 0; i <= len; i++)
	{
		printf("%3d ", i);
	}
	printf("\n A: ");
	for (int i = 0; i <= len; i++)
	{
		printf("%3d ", arr[i]);
	}
	printf("\nD1: ");
	for (int i = 0; i <= len; i++)
	{
		printf("%3d ", dp1[i]);
	}
	printf("\nD2: ");
	for (int i = 0; i <= len; i++)
	{
		printf("%3d ", dp2[i]);
	}
	printf("\n\n");
	*/
}