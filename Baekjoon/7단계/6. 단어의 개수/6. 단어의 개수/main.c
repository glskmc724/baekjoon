#include <stdio.h>

#define MAX_LENGTH 1000000

int main(void)
{
	char str[MAX_LENGTH];
	int length;
	int word, count;
	scanf("%[^\n]", str);
	length = strlen(str) + 1;
	count = 0;
	word = 0;
	str[length] = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			if (word == 1)
			{
				word = 0;
				count += 1;
			}
			continue;
		}
		else if (str[i] == 0)
		{
			if (word == 1)
			{
				count += 1;
			}
		}
		else
		{
			word = 1;
		}
	}
	printf("%d\n", count);
	return 0;
}