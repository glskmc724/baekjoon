#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, X;
	int* arr;

	scanf("%d %d", &N, &X);
	arr = (int*)malloc(sizeof(int) * N);
	for (int n = 0; n < N; n++)
	{
		scanf("%d", &arr[n]);
	}
	for (int n = 0; n < N; n++)
	{
		if (arr[n] < X)
		{
			printf("%d ", arr[n]);
		}
	}
	return 0;
}