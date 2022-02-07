#include <stdio.h>
#include <stdlib.h>

#define INT_MAX (2 << 30) - 1

int main(void)
{
	int num;
	int series_num;
	int count;
	char numstr[13];

	scanf("%d", &num);

	//for (int num = 1; num < 188; num++)
	{
		series_num = 0;
		for (int i = 666, count = 0; i < INT_MAX; i++)
		{
			if (series_num < i)
			{
				series_num = i;
				sprintf(numstr, "%d", series_num);

				for (int j = 0; j < 10; j++)
				{
					if (numstr[j] == '6' && numstr[j + 1] == '6' && numstr[j + 2] == '6')
					{
						count += 1;
						break;
					}
				}
			}

			if (num <= count)
			{
				break;
			}
		}
		printf("%d\n", series_num);
	}
}