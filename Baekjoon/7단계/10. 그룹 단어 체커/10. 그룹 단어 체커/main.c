#include <stdio.h>

#define MAX_LENGTH 100

int group_checker(char* str) // ccazzzzbb
{
	int length;
	int flag;

	length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (str[i] == str[j] && j - i == 1)
			{
				i += 1;
			}
			else if (str[i] == str[j] && j - i != 1)
			{
				return 0;
			}
		}
	}
	return 1;
}

int main(void)
{
	int count;
	int num_group;
	char str[MAX_LENGTH];
	scanf("%d", &count);
	num_group = 0;
	for (int i = 0; i < count; i++)
	{
		scanf("%s", str);
		if (group_checker(str) == 1)
		{
			num_group += 1;
		}
	}
	printf("%d\n", num_group);
	return 0;
}