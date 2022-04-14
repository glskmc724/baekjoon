#include <stdio.h>
#include <stdlib.h>

int arrmax(int* arr, int len, int std)
{
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		//printf("%d < %d && %d > %d\n", res, arr[i], std, arr[i]);
		if (res < arr[i] && std >= arr[i])
		{
			res = arr[i];
		}
	}
	return res;
}

int main(void)
{
	int num;
	int value;
	int* arr;
	int* greedy;
	int max;
	int count;

	scanf("%d %d", &num, &value);
	arr = (int*)malloc(sizeof(int) * num);
	greedy = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
		greedy[i] = arr[i];
	}
	count = 0;
	while (1)
	{
		max = arrmax(greedy, num, value);
		count += 1;
		if (max == value)
		{
			printf("%d\n", count);
			break;
		}
		for (int i = 0; i < num; i++)
		{
			greedy[i] = arr[i] + max;
		}
	}
}