#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} position;

void mergesort(position* arr, position* sorted, int left, int right)
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
		else if (arr[i].x <= arr[j].x)
		{
			if (arr[i].x == arr[j].x)
			{
				if (arr[i].y <= arr[j].y)
				{
					sorted[k] = arr[i++];
				}
				else
				{
					sorted[k] = arr[j++];
				}
			}
			else
			{
				sorted[k] = arr[i++];
			}
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

/*
int partition(position* arr, int left, int right, int pivot_idx)
{
	position temp;
	position pivot_value;
	int store_idx;

	pivot_value = arr[pivot_idx];
	store_idx = left;

	temp = arr[pivot_idx];
	arr[pivot_idx] = arr[right];
	arr[right] = temp;

	for (int i = left; i < right; i++)
	{
		if (arr[i].x < pivot_value.x)
		{
			temp = arr[i];
			arr[i] = arr[store_idx];
			arr[store_idx] = temp;
		}
		else if (arr[i].x == pivot_value.x)
		{
			if (arr[i].y < pivot_value.y)
			{
				temp = arr[i];
				arr[i] = arr[store_idx];
				arr[store_idx] = temp;
			}
		}
	}

	temp = arr[store_idx];
	arr[store_idx] = arr[right];
	arr[right] = temp;

	return store_idx;
}

void quicksort(position* arr, int left, int right)
{
	int pivot_idx;
	int new_pivot_idx;

	if (left >= right)
	{
		return;
	}
	else if (left < right)
	{
		pivot_idx = (left + right) / 2;
		new_pivot_idx = partition(arr, left, right, pivot_idx);

		if (left < new_pivot_idx - 1)
		{
			quicksort(arr, left, new_pivot_idx - 1);
		}

		if (new_pivot_idx + 1 < right)
		{
			quicksort(arr, new_pivot_idx + 1, right);
		}
	}
}
*/

int main(void)
{
	position* arr;
	position* sorted;
	int count;

	scanf("%d", &count);
	arr = (position*)malloc(sizeof(position) * count);
	sorted = (position*)malloc(sizeof(position) * count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	mergesort(arr, sorted, 0, count - 1);
	for (int i = 0; i < count; i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}