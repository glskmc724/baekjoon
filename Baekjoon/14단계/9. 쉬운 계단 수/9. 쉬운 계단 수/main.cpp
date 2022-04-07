#include <stdio.h>
#include <stdlib.h>

#define NUM_DECIMAL 10
#define NUM_MOD 1000000000

int main(void)
{
	int num;
	int** arr;
	long long sum;
	
	scanf("%d", &num);
	//num = i;
	arr = (int**)malloc(sizeof(int*) * (num + 1));
	for (int i = 0; i <= num; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * NUM_DECIMAL);
	}

	arr[1][0] = 0;
	for (int i = 1; i < NUM_DECIMAL; i++)
	{
		arr[1][i] = 1;
	}

	for (int i = 2; i < num + 1; i++)
	{
		for (int j = 0; j < NUM_DECIMAL; j++)
		{
			if (j == 0)
			{
				arr[i][j] = (arr[i - 1][j + 1]) % NUM_MOD;
			}
			else if (j == 9)
			{
				arr[i][j] = (arr[i - 1][j - 1]) % NUM_MOD;
			}
			else
			{
				arr[i][j] = (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % NUM_MOD;
			}
		}
	}

	sum = 0;
	for (int i = 0; i < NUM_DECIMAL; i++)
	{
		sum += arr[num][i];
	}
	sum %= NUM_MOD;
	printf("%d\n", sum);

}