#include <stdio.h>
#include <stdlib.h>

#define COUNT 9
#define MAX 100
#define MIN 0

int main(void)
{
	int min, max, count;
	int* arr;

	min = MAX;
	max = MIN;

	arr = (int*)malloc(sizeof(int) * COUNT);

	for (int n = 0; n < COUNT; n++)
	{
		scanf("%d", &arr[n]);

		if (max < arr[n])
		{
			max = arr[n];
			count = n + 1;
		}
	}
	printf("%d\n", max);
	printf("%d\n", count);

	return 0;
}