//
#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 10000 + 1

int main(void)
{
	int* arr;
	int length;
	int num;
	scanf("%d", &length);
	arr = (int*)malloc(sizeof(int) * NUM_MAX);
	for (int i = 0; i < NUM_MAX; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &num);
		arr[num] += 1;
	}
	for (int i = 0; i < NUM_MAX; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				printf("%d\n", i);
			}
		}
	}
}


/*
int main(void)
{
	int* arr;
	int* cnt_arr;
	int* sort_arr;
	int max = 0;
	int length;

	scanf("%d", &length);

	arr = (int*)malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cnt_arr = (int*)malloc(sizeof(int) * (max + 1));

	for (int i = 0; i < max + 1; i++)
	{
		cnt_arr[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		cnt_arr[arr[i]] += 1;
	}
	
	for (int i = 0; i < max; i++)
	{
		cnt_arr[i + 1] += cnt_arr[i];
	}

	sort_arr = (int*)malloc(sizeof(int) * length);

	for (int i = length - 1; i >= 0; i--)
	{
		//printf("정렬 대상: %d (%d)\n", arr[i], cnt_arr[arr[i]]);
		sort_arr[cnt_arr[arr[i]] - 1] = arr[i];
		cnt_arr[arr[i]] -= 1;
		//printf("cnt_arr: ");
		
		for (int i = 0; i < max + 1; i++)
		{
			printf("%3d ", cnt_arr[i]);
		}
		
		//printf("\n");
		//printf("sort_arr: ");
		
		for (int i = 0; i < length; i++)
		{
			printf("%3d ", sort_arr[i]);
		}
		
		//printf("\n");
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", sort_arr[i]);
	}

}

*/