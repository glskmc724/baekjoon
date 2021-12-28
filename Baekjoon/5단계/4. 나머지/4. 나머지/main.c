#include <stdio.h>
#include <stdlib.h>

#define COUNT 10
#define NUM_DIVIDE 42

int main(void)
{
	int* arr;
	int count = 0;
	int num;
	
	arr = (int*)malloc(sizeof(int) * NUM_DIVIDE);
	for (int n = 0; n < NUM_DIVIDE; n++)
	{
		arr[n] = 0;
	}
	for (int n = 0; n < COUNT; n++)
	{
		scanf("%d", &num);
		arr[num % NUM_DIVIDE] += 1;
	}
	for (int n = 0; n < NUM_DIVIDE; n++)
	{
		if (arr[n] >= 1)
		{
			count += 1;
		}
	}
	printf("%d\n", count);
	return 0;
}