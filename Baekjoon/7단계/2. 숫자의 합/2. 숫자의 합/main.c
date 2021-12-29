#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int length;
	char* str;
	int sum;

	scanf("%d", &length);
	str = (char*)malloc(sizeof(char) * length);

	scanf("%s", str);
	sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += (str[i] - '0');
	}
	printf("%d\n", sum);
}