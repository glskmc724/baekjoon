#include <stdio.h>

#define MAX_LENGTH 100

int main(void)
{
	char str[MAX_LENGTH];
	int count = 0;

	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] == 'c' && str[i + 1] == '=') ||
			(str[i] == 'c' && str[i + 1] == '-') ||
			(str[i] == 'd' && str[i + 1] == '-') ||
			(str[i] == 'l' && str[i + 1] == 'j') ||
			(str[i] == 'n' && str[i + 1] == 'j') ||
			(str[i] == 's' && str[i + 1] == '=') ||
			(str[i] == 'z' && str[i + 1] == '='))
		{
			i += 1;
		}
		else if ((str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '='))
		{
			i += 2;
		}
		count += 1;
	}
	printf("%d\n", count);
}