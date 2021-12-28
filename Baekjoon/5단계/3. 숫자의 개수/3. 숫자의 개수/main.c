#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

int main(void)
{
	int A, B, C;
	int res, res_tmp, length;
	int* arr;
	int count;

	scanf("%d %d %d", &A, &B, &C);
	res = res_tmp = A * B * C;
	length = 1;
	while (!(res_tmp < 10))
	{
		res_tmp /= 10;
		length += 1;
	}
	arr = (int*)malloc(sizeof(int) * length);
	for (int n = 0; n < length; n++)
	{
		arr[n] = res % 10;
		res /= 10;
	}

	for (int n = 0; n < COUNT; n++)
	{
		count = 0;
		for (int i = 0; i < length; i++)
		{
			if (arr[i] == n)
			{
				count += 1;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}