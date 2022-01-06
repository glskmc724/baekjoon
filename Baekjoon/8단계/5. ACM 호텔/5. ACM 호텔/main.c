#include <stdio.h>

int main(void)
{
	int count;
	int H, W, N; // H: Height, W: Width, N: Number of customer
	int height_num;
	int width_num;
	int room_num;

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %d %d", &H, &W, &N); 
		if (N % H == 0)
		{
			height_num = H;
		}
		else
		{
			height_num = N % H;
		}
		width_num = (N - 1) / H + 1;
		room_num = height_num * 100 + width_num;
		printf("%d\n", room_num);
	}
}