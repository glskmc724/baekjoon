#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 100 + 1

long long P(long long* arr, int N)
{
	if (arr[N] > 0)
	{
		return arr[N];
	}
	else
	{
		for (int i = 4; i <= N; i++)
		{
			arr[i] = arr[i - 2] + arr[i - 3];
		}
		return arr[N];
	}
}

int main(void)
{
	int T;
	int N;
	long long* arr;
	arr = (long long*)malloc(sizeof(long long) * NUM_MAX);
	scanf("%d", &T);
	arr[1] = arr[2] = arr[3] = 1;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		printf("%lld\n", P(arr, N));
	}
}