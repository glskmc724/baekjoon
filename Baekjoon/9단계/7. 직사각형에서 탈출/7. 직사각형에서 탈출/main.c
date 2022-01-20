#include <stdio.h>

int main(void)
{
	int x, y, w, h;
	int c_x, c_y;
	int dist_x, dist_y;
	int min_x, min_y;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	c_x = w / 2;
	c_y = h / 2;

	dist_x = x - c_x;
	dist_y = y - c_y;
	
	if (dist_x <= 0)
	{
		min_x = x;
		//printf("min_x=%d\n", x);
	}
	else
	{
		min_x = w - x;
		//printf("min_x=%d\n", w - x);
	}

	if (dist_y <= 0)
	{
		min_y = y;
		//printf("min_y=%d\n", y);
	}
	else
	{
		min_y = h - y;
		//printf("min_y=%d\n", h - y);
	}

	if (min_x > min_y)
	{
		printf("%d\n", min_y);
	}
	else
	{
		printf("%d\n", min_x);
	}
}