#include <stdio.h>

int main(void)
{
	unsigned int A, B, C;
	int count;

	scanf("%d %d %d", &A, &B, &C);

	if (B >= C)
	{
		printf("-1\n");
	}
	else
	{
		count = A / (C - B) + 1;
		printf("%d\n", count);
	}
}