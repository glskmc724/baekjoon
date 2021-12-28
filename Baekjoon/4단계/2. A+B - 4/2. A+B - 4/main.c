#include <stdio.h>

int main(void)
{
	int A, B, result;
	while (1)
	{
		result = scanf("%d %d", &A, &B);
		if (result == EOF || result == -1)
		{
			break;
		}
		else
		{
			printf("%d\n", A + B);
		}
	}
}