#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count, score;
	double* arr;
	int max = 0;
	double avg = 0;

	scanf("%d", &count);
	arr = (double*)malloc(sizeof(double) * count);
	for (int n = 0; n < count; n++)
	{
		scanf("%d", &score);
		arr[n] = (double)score;
		if (score > max)
		{
			max = score;
		}
	}
	for (int n = 0; n < count; n++)
	{
		arr[n] = (arr[n] / max) * 100;
		avg += arr[n];
	}

	avg /= count;
	printf("%lf\n", avg);

	return 0;
}