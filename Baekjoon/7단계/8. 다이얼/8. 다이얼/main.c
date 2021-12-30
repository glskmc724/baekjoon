#include <stdio.h>

#define MAX_LENGTH 15
#define NUM_ALPHABET 26

int main(void)
{
	int sum;
	char str[MAX_LENGTH + 1];
	char alphabet[NUM_ALPHABET] = {
		3, 3, 3, 4, 4, 4, 5, 5, 5, // A B C D E F G H I
		6, 6, 6, 7, 7, 7, 8, 8, 8, 8, // J K L M N O P Q R S
		9, 9, 9, 10, 10, 10, 10 // T U V W X Y Z
	};

	scanf("%s", str);
	sum = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < NUM_ALPHABET; j++)
		{
			if (str[i] == j + 'A')
			{
				sum += alphabet[j];
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}