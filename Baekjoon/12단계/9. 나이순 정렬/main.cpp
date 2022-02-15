#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 101

typedef struct
{
	int idx;
	int age;
	char str[MAX_LENGTH];
} member;

void mergesort(member* arr, member* sorted, int left, int right)
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

	for (; k <= right; ++k)
	{
		if (j > right)
		{
			sorted[k] = arr[i++];
		}
		else if (i > mid)
		{
			sorted[k] = arr[j++];
		}
		else if (arr[i].age <= arr[j].age)
		{
			if (arr[i].age == arr[j].age)
			{
				if (arr[i].idx <= arr[j].idx)
				{
					sorted[k] = arr[i++];
				}
				else
				{
					sorted[k] = arr[j++];
				}
			}
			else
			{
				sorted[k] = arr[i++];
			}
		}
		else
		{
			sorted[k] = arr[j++];
		}
	}

	for (i = left; i <= right; ++i)
	{
		arr[i] = sorted[i];
	}
}


int main(void)
{
	int count;
	member* memarr;
	member* sorted;

	scanf("%d", &count);

	memarr = (member*)malloc(sizeof(member) * count);
	sorted = (member*)malloc(sizeof(member) * count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %s", &memarr[i].age, memarr[i].str);
		memarr[i].idx = i;
	}

	mergesort(memarr, sorted, 0, count - 1);

	for (int i = 0; i < count; i++)
	{
		printf("%d %s\n", memarr[i].age, memarr[i].str);
	}
}