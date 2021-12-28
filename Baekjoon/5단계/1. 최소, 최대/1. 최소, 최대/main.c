#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 10000000
#define NUM_MIN -10000000

int main(void)
{
	int count;
	int* arr;
	int num, min, max;

	min = NUM_MAX;
	max = NUM_MIN;

	scanf("%d", &count);
	arr = (int*)malloc(sizeof(int) * count);
	for (int n = 0; n < count; n++)
	{
		scanf("%d", &num);
		arr[n] = num;
	}

	for (int n = 0; n < count; n++)
	{
		if (min > arr[n])
		{
			min = arr[n];
		}
		if (max < arr[n])
		{
			max = arr[n];
		}
	}
	printf("%d %d\n", min, max);
}