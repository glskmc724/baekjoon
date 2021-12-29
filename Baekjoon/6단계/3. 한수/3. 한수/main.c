#include <stdio.h>
#include <stdlib.h>

int is_hansu(int n)
{
	int num = 0;
	int count = 0;
	int length = 0;
	int d;
	int* arr;

	num = n;
	while (num > 0)
	{
		num /= 10;
		length += 1;
	}

	arr = (int*)malloc(sizeof(int) * length);

	for (int i = n; i > 0; i = i / 10)
	{
		num = i % 10;
		arr[count++] = num;
	}

	d = arr[0] - arr[1];
	for (int i = 1; i < length - 1; i++)
	{
		if (arr[i] - arr[i + 1] != d)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int input;
	int count;
	count = 0;
	scanf("%d", &input);
	for (int i = 1; i <= input; i++)
	{
		if (is_hansu(i) == 1)
		{
			count += 1;
		}
	}
	printf("%d\n", count);
}