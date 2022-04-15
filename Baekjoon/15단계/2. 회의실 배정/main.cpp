#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int start;
	int end;
} group;

void mergesort(group* arr, group* sorted, int left, int right)
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
		else if (arr[i].end <= arr[j].end)
		{
			if (arr[i].end == arr[j].end)
			{
				if (arr[i].start <= arr[j].start)
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
	int num;
	group* arr;
	group* sorted;
	int last_end;
	int count;
	scanf("%d", &num);
	arr = (group*)malloc(sizeof(group) * num);
	sorted = (group*)malloc(sizeof(group) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}
	mergesort(arr, sorted, 0, num - 1);
	/*
	printf("SORTED:\n");
	for (int i = 0; i < num; i++)
	{
		printf("%3d %3d\n", arr[i].start, arr[i].end);
	}
	printf("SOLVING:\n");
	*/
	last_end = arr[0].end;
	count = 1;
	//printf("%3d %3d\n", arr[0].start, arr[0].end);
	for (int i = 1; i < num; i++)
	{
		if (!(arr[i].start < last_end))
		{
			last_end = arr[i].end;
			//printf("%3d %3d\n", arr[i].start, arr[i].end);
			count += 1;
		}
	}
	printf("%d\n", count);
}