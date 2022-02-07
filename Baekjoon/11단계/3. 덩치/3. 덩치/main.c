#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int weight;
	int height;
	int rank;
} balance;

int main(void)
{
	balance* arr;
	int num;
	int rank;

	scanf("%d", &num);
	arr = (balance*)malloc(sizeof(balance) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &arr[i].weight, &arr[i].height);
	}

	for (int i = 0; i < num; i++)
	{
		rank = 1;
		for (int j = 0; j < num; j++)
		{
			if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
			{
				rank += 1;
			}
		}
		arr[i].rank = rank;
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i].rank);
	}
	printf("\n");
}