#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	unsigned int x, y, dist;
	unsigned int result, warp, move_cnt, rest, more_move;
	unsigned int loop;

	scanf("%d", &loop);
	for (unsigned int i = 0; i < loop; i++)
	{
		scanf("%d %d", &x, &y);
		dist = y - x;
		result = sqrt(dist);
		warp = result * result;
		rest = dist - warp;
		move_cnt = 2 * result - 1;
		more_move = ceil((double)rest / result);
		printf("%d\n", move_cnt + more_move);
	}
}