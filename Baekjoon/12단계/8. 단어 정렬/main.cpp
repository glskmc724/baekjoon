#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 56

typedef struct
{
	char str[MAX_LENGTH];
	int length;
	int count;
} string;

void mergesort(string* arr, string* sorted, int left, int right)
{
	int mid;
	int i, j, k;

	if (left >= right)
	{
		return;
	}

	mid = (left + right) / 2;
	mergesort(arr, sorted, left, mid);
	mergesort(arr, sorted, mid + 1, right);

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i].length < arr[j].length)
		{
			sorted[k++] = arr[i++];
		}
		else if (arr[i].length == arr[j].length)
		{
			if (strcmp(arr[i].str, arr[j].str) < 0)
			{
				sorted[k++] = arr[i++];
			}
			else
			{
				sorted[k++] = arr[j++];
			}
		}
		else
		{
			sorted[k++] = arr[j++];
		}
	}


	if (i > mid)
	{
		while (j <= right)
		{
			sorted[k++] = arr[j++];
		}
	}
	else
	{
		while (i <= mid)
		{
			sorted[k++] = arr[i++];
		}
	}
	/*
	for (; k <= right; ++k)
	{
		if (j > right)
		{
			sorted[k] = arr[i++];
			//memcpy(&sorted[k], &arr[i++], sizeof(string));
		}
		else if (i > mid)
		{
			sorted[k] = arr[j++];
			//memcpy(&sorted[k], &arr[j++], sizeof(string));
		}
		else if (strlen(arr[i].str) < strlen(arr[j].str))
		{
			sorted[k] = arr[i++];
			//memcpy(&sorted[k], &arr[i++], sizeof(string));
		}
		else if (strlen(arr[i].str) == strlen(arr[j].str))
		{
			if (strcmp(arr[i].str, arr[j].str) < 0)
			{
				sorted[k] = arr[i++];
				//memcpy(&sorted[k], &arr[i++], sizeof(string));
			}
			else
			{
				sorted[k] = arr[j++];
				//memcpy(&sorted[k], &arr[j++], sizeof(string));
			}
		}
		else
		{
			sorted[k] = arr[j++];
			//memcpy(&sorted[k], &arr[j++], sizeof(string));
		}
	}
	*/

	for (i = left; i <= right; i++)
	{
		arr[i] = sorted[i];
		//memcpy(&arr[i], &sorted[i], sizeof(string));
	}
}

/*
void selection_sort(string* arr, int length)
{
	int min;
	char temp[MAX_LENGTH];

	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (strlen(arr[j].str) < strlen(arr[min].str))
			{
				min = j;
			}
			else if (strlen(arr[j].str) == strlen(arr[min].str))
			{
				if (strcmp(arr[j].str, arr[min].str) < 0)
				{
					min = j;
				}
			}
		}
		if (i != min)
		{
			strcpy(temp, arr[i].str);
			strcpy(arr[i].str, arr[min].str);
			strcpy(arr[min].str, temp);
		}
	}
}
*/
/*
int compare(const void* first, const void* second)
{
	string d1 = *(string*)first;
	string d2 = *(string*)second;

	if (strlen(d1.str) < strlen(d2.str))
	{
		return 0;
	}
	else if (strlen(d1.str) == strlen(d2.str))
	{
		if (strcmp(d1.str, d2.str) < 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}
*/
int main(void)
{
	int count;
	string* strarr;
	string* sorted;

	scanf("%d", &count);
	strarr = (string*)malloc(sizeof(string) * count);
	sorted = (string*)malloc(sizeof(string) * count);
	for (int i = 0; i < count; i++)
	{
		scanf("%s", strarr[i].str);
		strarr[i].count = 0;
		strarr[i].length = strlen(strarr[i].str);
		for (int j = 0; j < i; j++)
		{
			if (strcmp(strarr[i].str, strarr[j].str) == 0)
			{
				strarr[j].count += 1;
			}
		}
	}
	mergesort(strarr, sorted, 0, count - 1);
	//qsort(strarr, count, sizeof(string), compare);
	/*
	for (int i = 0; i < count; i++)
	{
		if (strarr[i].count == 0)
		{
			printf("%s\n", strarr[i].str);
		}
	}
	*/
	printf("%s\n", strarr[0].str);
	for (int i = 1; i < count; i++)
	{
		if (strcmp(strarr[i - 1].str, strarr[i].str) != 0)
		{
			printf("%s\n", strarr[i].str);
		}
	}
}