#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 10

int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main(void)
{
	int num;
	int* arr;

	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * (num + 1));

	arr[0] = arr[1] = 0;
	for (int i = 2; i <= num; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
	}

	printf("%d\n", arr[num]);
}
