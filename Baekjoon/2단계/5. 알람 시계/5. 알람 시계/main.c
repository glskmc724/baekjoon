#include <stdio.h>

#define WAKEUP_TIME_MIN 45

int main(void)
{
	int H, M;

	scanf("%d %d", &H, &M);

	M = M - WAKEUP_TIME_MIN;

	if (M < 0)
	{
		if ((H - 1) < 0)
		{
			H = 23;
		}
		else
		{
			H = H - 1;
		}
		M = M + 60;
	}

	printf("%d %d", H, M);

	return 0;
}