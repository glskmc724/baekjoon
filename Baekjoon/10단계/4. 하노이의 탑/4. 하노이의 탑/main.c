#include <stdio.h>

void hanoi(int from, int to, int n)
{
	if (n == 1)
	{
		printf("%d %d\n", from, to);
		return;
	}

	int empty = 6 - from - to;
	hanoi(from, empty, n - 1);
	printf("%d %d\n", from, to);
	hanoi(empty, to, n - 1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoi(1, 3, n);
}