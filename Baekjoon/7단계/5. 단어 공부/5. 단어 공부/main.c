#include <stdio.h>

#define MAX_LENGTH 1000000
#define NUM_ALPHABET 26

int main(void)
{
	char word[MAX_LENGTH];
	int arr[NUM_ALPHABET];
	int length;
	int max, pos;
	int count;

	scanf("%s", word);
	length = strlen(word);
	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < NUM_ALPHABET; j++)
		{
			if (word[i] == 'a' + j || word[i] == 'A' + j)
			{
				arr[j] += 1;
			}
		}
	}

	max = 0;
	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			pos = i;
		}
	}

	count = 0;
	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		if (arr[i] == max)
		{
			count += 1;
		}
	}

	if (count > 1)
	{
		printf("?\n");
	}
	else
	{
		printf("%c\n", pos + 'A');
	}
	return 0;
}