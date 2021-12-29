#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

int main(void)
{
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
	{
		int repeat;
		int length, new_length;
		char str[MAX_LENGTH];
		char* new_str;
		scanf("%d", &repeat);
		scanf("%s", str);
		length = strlen(str);
		new_length = length * repeat;
		new_str = (char*)malloc(sizeof(char) * new_length + 1);
		for (int j = 0; j < new_length; j++)
		{
			new_str[j] = str[j / repeat];
		}
		new_str[new_length] = 0;
		printf("%s\n", new_str);
	}
	return 0;
}