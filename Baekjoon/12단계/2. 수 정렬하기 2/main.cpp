#include <stdio.h>
#include <stdlib.h>

void mergesort(int* arr, int* sorted, int left, int right)
{
	int mid;
	int i, j, k;

	if (left >= right)
	{
		return;
	}

	mid = (left + right) / 2;
	mergesort(arr, sorted, left, mid);
	mergesort(arr, sorted, mid + 1, right);

	i = left;
	j = mid + 1;
	k = left;

	for (; k <= right; ++k)
	{
		if (j > right)
		{
			sorted[k] = arr[i++];
		}
		else if (i > mid)
		{
			sorted[k] = arr[j++];
		}
		else if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i++];
		}
		else
		{
			sorted[k] = arr[j++];
		}
	}

	for (i = left; i <= right; ++i)
	{
		arr[i] = sorted[i];
	}
}

int main(void)
{
	int count;
	int* arr;
	int* sorted;
	scanf("%d", &count);
	arr = (int*)malloc(sizeof(int) * count);
	sorted = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergesort(arr, sorted, 0, count - 1);
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", arr[i]);
	}
}