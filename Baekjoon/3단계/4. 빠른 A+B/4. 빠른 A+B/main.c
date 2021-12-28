#include <stdio.h>

int main(void)
{
	int count;
	int A, B;

	scanf("%d", &count);
	for (int n = 0; n < count; n++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}
	return 0;
}