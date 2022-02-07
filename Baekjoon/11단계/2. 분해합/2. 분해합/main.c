#include <stdio.h>

int sum_of_num(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(void)
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		if (i + sum_of_num(i) == num)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");
}