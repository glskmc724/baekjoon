#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int count;
	int floor; // k
	int room; // n
	int** arr;
	int people = 0;

	scanf("%d", &count);
	for (int loop = 0; loop < count; loop++)
	{
		scanf("%d", &floor);
		scanf("%d", &room);

		arr = (int**)malloc(sizeof(int*) * (floor + 1));
		for (int i = 0; i < floor + 1; i++)
		{
			arr[i] = (int*)malloc(sizeof(int) * room);
		}

		for (int i = 0; i < floor + 1; i++)
		{
			for (int j = 0; j < room; j++)
			{
				arr[i][j] = 0;
			}
		}

		for (int i = 0; i < floor + 1; i++)
		{
			arr[i][0] = 1;
		}

		for (int i = 0; i < room; i++)
		{
			arr[0][i] = i + 1;
		}

		for (int i = 1; i < floor + 1; i++)
		{
			for (int j = 1; j < room; j++)
			{
				arr[i][j] += (arr[i - 1][j] + arr[i][j - 1]);
			}
		}

		printf("%d\n", arr[floor][room - 1]);
	}
}