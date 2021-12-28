#include <stdio.h>

int main(void)
{
	int origin_num; // AB
	int num, A, B, sum, length; // ex) 10, A = 1,B = 0
	scanf("%d", &origin_num);

	if (origin_num < 10)
	{
		origin_num *= 10;
	}
	num = origin_num;

	length = 0;
	while (1)
	{
		A = num / 10;
		B = num % 10;
		sum = A + B;
		num = B * 10 + sum % 10;
		length += 1;
		//printf("%d\n", num);
		if (num == origin_num)
		{
			break;
		}
	}
	printf("%d\n", length);
}