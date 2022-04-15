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
	int num;
	int* arr;
	int* greedy;
	int result;

	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num);
	greedy = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	selection_sort(arr, num);
	for (int i = 0; i < num; i++)
	{
		greedy[i] = arr[i];
	}
	result = greedy[0];
	for (int i = 1; i < num; i++)
	{
		greedy[i] += greedy[i - 1];
		result += greedy[i];
	}
	printf("%d\n", result);
}