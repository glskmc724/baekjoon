#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count, std_cnt;
	int* arr;
	int sum;
	int clever_std_cnt;
	double avg;
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &std_cnt);
		arr = (int*)malloc(sizeof(int) * std_cnt);
		for (int n = 0; n < std_cnt; n++)
		{
			scanf("%d", &arr[n]);
		}

		sum = 0;
		for (int n = 0; n < std_cnt; n++)
		{
			sum += arr[n];
		}

		avg = (double)sum / std_cnt;
		clever_std_cnt = 0;
		for (int n = 0; n < std_cnt; n++)
		{
			if (avg < (double)arr[n])
			{
				clever_std_cnt += 1;
			}
		}
		printf("%.3lf%%\n", ((double)clever_std_cnt / std_cnt) * 100);
	}
	return 0;
}