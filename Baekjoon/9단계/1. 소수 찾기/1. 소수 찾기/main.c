#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
	if (n == 1)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int num;
	int* arr;
	int count;

	scanf("%d\n", &num);
	arr = (int*)malloc(sizeof(int) * num);
	count = 0;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
		if (is_prime(arr[i]) == 1)
		{
			count += 1;
		}
	}
	printf("%d\n", count);
}