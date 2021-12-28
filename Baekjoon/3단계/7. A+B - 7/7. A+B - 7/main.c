#include <stdio.h>

int main(void)
{
	int max;
	int A, B;

	scanf("%d", &max);
	for (int n = 0; n < max; n++)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", n + 1, A + B);
	}
	return 0;
}