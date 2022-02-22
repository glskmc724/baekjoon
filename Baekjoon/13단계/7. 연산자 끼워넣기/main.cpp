#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_OPERATION 4

int min = INT_MAX;
int max = INT_MIN;

typedef struct
{
	int plus;
	int minus;
	int multiple;
	int divide;
} opercnt;

void check(int* arr, opercnt cnt, int length, int result, int count)
{

	if (count == length - 1)
	{
		if (max < result)
		{
			max = result;
		}

		if (min > result)
		{
			min = result;
		}
		return;
	}

	if (cnt.plus > 0)
	{
		cnt.plus -= 1;
		count += 1;
		check(arr, cnt, length, result + arr[count], count);
		cnt.plus += 1;
		count -= 1;
	}

	if (cnt.minus > 0)
	{
		cnt.minus -= 1;
		count += 1;
		check(arr, cnt, length, result - arr[count], count);
		cnt.minus += 1;
		count -= 1;
	}

	if (cnt.multiple > 0)
	{
		cnt.multiple -= 1;
		count += 1;
		check(arr, cnt, length, result * arr[count], count);
		cnt.multiple += 1;
		count -= 1;
	}

	if (cnt.divide > 0)
	{
		cnt.divide -= 1;
		count += 1;
		check(arr, cnt, length, result / arr[count], count);
		cnt.divide += 1;
		count -= 1;
	}
}

int main(void)
{
	int N;
	int* arr;
	opercnt cnt;

	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d %d", &cnt.plus, &cnt.minus, &cnt.multiple, &cnt.divide);

	check(arr, cnt, N, arr[0], 0);

	printf("%d\n", max);
	printf("%d\n", min);
}