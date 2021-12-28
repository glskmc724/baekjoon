#include <stdio.h>

int main(void)
{
	int loop_count;
	int A, B;

	scanf("%d", &loop_count);

	for (int n = 0; n < loop_count; n++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}