#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int weight;
	int* arr;
	int height;

	scanf("%d", &weight);
	arr = (int*)malloc(sizeof(int) * weight);
	for (int i = 0; i < weight; i++)
	{
		arr[i] = 12345;
	}

	arr[2] = arr[4] = 1;
	for (int i = 5; i < weight; i++)
	{
		if (arr[i - 3] < arr[i - 5])
		{
			arr[i] = arr[i - 3] + 1;
		}
		else
		{
			arr[i] = arr[i - 5] + 1;
		}
	}

	if (arr[weight - 1] >= 12345)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", arr[weight - 1]);
	}
	return 0;
}