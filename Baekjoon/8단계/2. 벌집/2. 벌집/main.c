#include <stdio.h>

#define COMM_DIFF 6

int main(void)
{
	int num;
	int comm_diff;
	int count;
	int sum;

	scanf("%d", &num);

	comm_diff = 1;
	count = 0;
	sum = 0;
	while (1)
	{
		if (sum >= num)
		{
			break;
		}
		sum += comm_diff;
		count += 1;
		comm_diff = (COMM_DIFF * count);
	}
	printf("%d\n", count);
}