#include <stdio.h>
#include <stdlib.h>

#define COUNT 10
#define NUM_DIVIDE 42

int main(void)
{
	int* arr;
	int count = 0;
	
	arr = (int*)malloc(sizeof(int) * COUNT);
	
	for (int n = 0; n < COUNT; n++)
	{
		scanf("%d", &arr[n]);
	}

	for (int n = 0; n < COUNT; n++)
	{
		arr[n] %= NUM_DIVIDE;
	}

	for (int n = 0; n < COUNT; n++)
	{
		int result = 0;
		for (int i = n + 1; i < COUNT; i++)
		{
			if (arr[n] == arr[i])
			{
				result = 1;
			}
		}
		if (result != 1)
		{
			count += 1;
		}
	}
	printf("%d\n", count);
	return 0;
}