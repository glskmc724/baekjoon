#include <stdio.h>

int main(void)
{
	// 높이: V
	// 이동: A
	// 미끌: B
	int A, B, V; 
	int day;
	int pos;

	scanf("%d %d %d", &A, &B, &V);
	pos = A - B;
	if ((V - B) % pos == 0)
	{
		day = (V - B) / pos;
	}
	else
	{
		day = (V - B) / pos + 1;
	}
	/*
	pos = 0;
	day = 0;
	while (1)
	{
		day += 1;
		pos += A;
		if (pos >= V)
		{
			break;
		}
		pos -= B;
	}
	*/
	printf("%d\n", day);
}