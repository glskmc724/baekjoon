#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_ALPHABET 26

int main(void)
{
	char str[MAX_LENGTH];
	char arr[NUM_ALPHABET];

	scanf("%s", str);

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		arr[i] = -1;
	}

	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < NUM_ALPHABET; j++)
		{
			if (str[i] == j + 'a' && arr[j] == -1)
			{
				arr[j] = i;
			}
		}
	}

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}