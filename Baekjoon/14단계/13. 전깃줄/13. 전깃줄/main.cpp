#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

typedef struct
{
	int A;
	int B;
} p2p;

void selection_sort(p2p* arr, int length)
{
	int min;
	p2p temp;

	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j].A < arr[min].A)
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main(void)
{
	int len;
	p2p* arr;
	int* dp;
	int idx, last_value;
	int result;

	scanf("%d", &len);
	arr = (p2p*)malloc(sizeof(p2p) * (len + 1));
	dp = (int*)malloc(sizeof(int) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		scanf("%d %d", &arr[i + 1].A, &arr[i + 1].B);
	}

	for (int i = 0; i <= len; i++)
	{
		dp[i] = 0;
	}

	selection_sort(arr, len + 1);

	arr[0].A = arr[0].B = dp[0] = 0;
	idx = 0;
	for (int i = 1; i <= len; i++)
	{
		last_value = 0;
		for (int j = 0; j <= i; j++)
		{
			if (arr[i].B > arr[j].B)
			{
				last_value = max(last_value, dp[j]);
			}
		}
		dp[i] = last_value + 1;
		/*
		printf("idx: %d\n", idx);
		printf("dp: %d\n", dp[i]);

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
			printf("%3d ", dp[i]);
		}
		printf("\n\n");
		*/
	}

	result = 0;
	for (int i = 1; i <= len; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
		//printf("%d\n", dp[i]);
	}
	result = len - result;
	printf("%d\n", result);
}