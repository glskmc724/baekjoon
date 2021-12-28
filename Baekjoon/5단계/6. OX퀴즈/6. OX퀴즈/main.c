#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 80

int main(void)
{
	int count;
	int sum;
	char* answer;

	answer = (char*)malloc(sizeof(char) * MAX_LENGTH);
	scanf("%d", &count);
	for (int n = 0; n < count; n++)
	{
		int acc;
		scanf("%s", answer);
		acc = sum = 0;
		for (int idx = 0; idx < strlen(answer); idx++)
		{
			if (answer[idx] == 'O')
			{
				acc += 1;
				sum += acc;
			}
			else
			{
				acc = 0;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}