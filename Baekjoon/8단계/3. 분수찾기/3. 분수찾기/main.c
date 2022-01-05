#include <stdio.h>

int main(void)
{
	int num;
	int x, y;
	int max_x, max_y;
	int count;
	int loop;

	scanf("%d", &num);

	loop = 0;
	count = 0;
	while (count < num)
	{
		max_x = loop * 2 + 1;
		for (int i = 0; i < max_x; i++)
		{
			if (count < num)
			{
				x = i + 1;
				//printf("%d", i + 1);
				count += 1;
			}
			else
			{
				break;
			}
		}
		for (int i = max_x - 1; i > 0; i--)
		{
			if (count < num)
			{
				x = i;
				//printf("%d", i);
				count += 1;
			}
			else
			{
				break;
			}
		}
		loop += 1;
		//printf("\n");
	}
	loop = 0;
	count = 0;
	while (count < num)
	{
		max_y = (loop + 1) * 2;
		for (int i = 0; i < max_y; i++)
		{
			if (count < num)
			{
				y = i + 1;
				//printf("%d", i + 1);
				count += 1;
			}
			else
			{
				break;
			}
		}
		for (int i = max_y - 1; i > 0; i--)
		{
			if (count < num)
			{
				y = i;
				//printf("%d", i);
				count += 1;
			}
			else
			{
				break;
			}
		}
		loop += 1;
		//printf("\n");
	}
	printf("%d/%d\n", x, y);
}