#include <stdio.h>
#include <stdlib.h>

void reverse(char* arr)
{
	char tmp;

	for (int i = 0; i < strlen(arr) / 2; i++)
	{
		tmp = arr[strlen(arr) - (i + 1)];
		arr[strlen(arr) - (i + 1)] = arr[i];
		arr[i] = tmp;
	}
}

int main(void)
{
	char A[10002];
	char B[10002];
	char res[10003];
	int carry;
	int result;
	int length;

	scanf("%s %s", A, B);

	if (strlen(A) < strlen(B))
	{
		length = strlen(B);
	}
	else
	{
		length = strlen(A);
	}

	carry = 0;
	result = 0;
	reverse(A);
	reverse(B);
	for (int i = 0;i < length; i++)
	{
		if (A[i] < '0')
		{
			A[i] = '0';
		}
		if (B[i] < '0')
		{
			B[i] = '0';
		}
		result = A[i] - '0' + B[i] - '0';
		if (carry == 1)
		{
			result += 1;
		}
		if (result >= 10)
		{
			carry = 1;
			result -= 10;
		}
		else
		{
			if (carry == 1)
			{
				carry -= 1;
			}
		}
		res[i] = result + '0';
	}
	if (carry == 1)
	{
		res[length] = '1';
		res[length + 1] = 0;
	}
	else
	{
		res[length] = 0;
	}
	reverse(res);
	printf("%s\n", res);
}
// 9,223,372,036,854,775,807