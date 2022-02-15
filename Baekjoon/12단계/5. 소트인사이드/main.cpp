#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

void selection_sort(char* arr, int length)
{
	int max, temp;

	for (int i = 0; i < length - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}
		if (i != max)
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

int main(void)
{
	char str[MAX_LENGTH];
	
	scanf("%s", str);

	selection_sort(str, strlen(str));
	printf("%s\n", str);
}