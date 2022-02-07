#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
	int n, m;
	int* arr;
	int sum;
	int min;
	int min_sum;

	scanf("%d %d", &n, &m);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	min = 1234567;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (abs(sum - m) < min && sum <= m)
				{
					min = abs(sum - m);
					min_sum = sum;
				}
			}
		}
	}
	printf("%d\n", min_sum);
}