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
		else if (arr[i].y <= arr[j].y)
		{
			if (arr[i].y == arr[j].y)
			{
				if (arr[i].x <= arr[j].x)
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