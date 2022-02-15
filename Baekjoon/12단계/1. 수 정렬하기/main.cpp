#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* arr, int length)
{
	int min, temp;

	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[min])
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
	int count;
	int* arr;
	scanf("%d", &count);
	arr = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &arr[i]);
	}
	selection_sort(arr, count);
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", arr[i]);
	}
}