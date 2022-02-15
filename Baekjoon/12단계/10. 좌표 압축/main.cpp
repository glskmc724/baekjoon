#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int idx;
	int orgpos;
	int compos;
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
		else if (arr[i].orgpos < arr[j].orgpos)
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

void mergesort2(position* arr, position* sorted, int left, int right)
{
	int mid;
	int i, j, k;

	if (left >= right)
	{
		return;
	}

	mid = (left + right) / 2;
	mergesort2(arr, sorted, left, mid);
	mergesort2(arr, sorted, mid + 1, right);

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
		else if (arr[i].idx < arr[j].idx)
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
	position* numarr;
	position* orgarr;
	position* sorted;
	int idx = 0;

	scanf("%d", &count);

	numarr = (position*)malloc(sizeof(position) * (count + 1));
	sorted = (position*)malloc(sizeof(position) * count);

	for (int i = 0; i < count; i++)
	{
		numarr[i].idx = i;
		scanf("%d", &numarr[i].orgpos);
	}

	mergesort(numarr, sorted, 0, count - 1);

	for (int i = 0; i < count; i++)
	{
		if (numarr[i + 1].orgpos == numarr[i].orgpos)
		{
			numarr[i].compos = idx;
		}
		else
		{
			numarr[i].compos = idx;
			idx += 1;
		}
	}
	/*
	for (int i = 0; i < count; i++)
	{
		printf("%d ", numarr[i].compos);
	}
	printf("\n");
	*/
	free(sorted);
	sorted = (position*)malloc(sizeof(position) * count);
	mergesort2(numarr, sorted, 0, count - 1);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", numarr[i].compos);
	}
	printf("\n");
}