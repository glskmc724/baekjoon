//
#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX (4000 + 1)

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
	int length;
	int* arr;
	int* sorted;
	int* numarr;
	int max = -12345;
	int arrmax = -12345;
	int arrmin = 12345;
	int sum;
	double avg;
	int mid;
	int mode_count;
	int* mode_arr;
	scanf("%d", &length);
	arr = (int*)malloc(sizeof(int) * length);
	sorted = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
	}
	numarr = (int*)malloc(sizeof(int) * (NUM_MAX * 2));
	for (int i = 0; i < NUM_MAX * 2; i++)
	{
		numarr[i] = 0;
	}
	sum = 0;
	mergesort(arr, sorted, 0, length - 1);
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
		numarr[NUM_MAX + arr[i] - 1] += 1;
		if (arrmax < arr[i])
		{
			arrmax = arr[i];
		}
		if (arrmin > arr[i])
		{
			arrmin = arr[i];
		}
	}
	avg = (double)sum / length;
	mid = arr[length / 2];
	max = 0;
	mode_count = 0;
	for (int i = 0; i < NUM_MAX * 2; i++)
	{
		if (numarr[i] > max)
		{
			max = numarr[i];
		}

		if (numarr[i] == max)
		{
			mode_count += 1;
		}
	}
	mode_arr = (int*)malloc(sizeof(int) * mode_count);
	mode_count = 0;
	for (int i = 0; i < NUM_MAX * 2; i++)
	{
		if (numarr[i] == max)
		{
			mode_arr[mode_count] = i - NUM_MAX + 1;
			mode_count += 1;
		}
	}
	if (avg < 0)
	{
		printf("%d\n", (int)(avg - 0.5));
	}
	else
	{
		printf("%d\n", (int)(avg + 0.5));
	}
	printf("%d\n", mid);
	if (mode_count == 1)
	{
		printf("%d\n", mode_arr[0]);
	}
	else
	{
		printf("%d\n", mode_arr[1]);
	}
	printf("%d\n", arrmax - arrmin);
}