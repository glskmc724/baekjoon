#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a < b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main(void)
{
	int num;
	int* stair;
	int* value;
	int count;

	scanf("%d", &num);
	stair = (int*)malloc(sizeof(int) * num);
	value = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &stair[i]);
	}

	value[0] = stair[0];
	value[1] = max((stair[0] + stair[1]), stair[1]);
	value[2] = max((stair[0] + stair[2]), (stair[2] + stair[1]));

	for (int i = 3; i < num; i++)
	{
		value[i] = max((value[i - 2] + stair[i]), (stair[i] + stair[i - 1] + value[i - 3]));
	}

	
	printf("result:\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", value[i]);
	}
	
	//printf("%d\n", value[num - 1]);
}
