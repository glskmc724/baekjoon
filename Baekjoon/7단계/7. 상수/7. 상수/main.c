#include <stdio.h>
#include <stdlib.h>

#define NUM_DIGIT 3

char* reverse(char* str)
{
	char* tmp = (char*)malloc(sizeof(char) * NUM_DIGIT);
	for (int i = 0; i < NUM_DIGIT; i++)
	{
		tmp[i] = str[NUM_DIGIT - i - 1];
	}
	return tmp;
}

int stoi(char* str)
{
	int digit;
	int sum;

	sum = 0;
	for (int i = 0; i < NUM_DIGIT; i++)
	{
		digit = 1;
		for (int j = NUM_DIGIT - i - 1; j > 0; j--)
		{
			digit *= 10;
		}
		sum += (str[i] - '0') * digit;
	}
	return sum;
}

int main(void)
{
	char* A;
	char* reverse_A;
	char* B;
	char* reverse_B;
	int result_A, result_B;

	A = (char*)malloc(sizeof(char) * NUM_DIGIT);
	B = (char*)malloc(sizeof(char) * NUM_DIGIT);

	scanf("%s %s", A, B);
	reverse_A = reverse(A);
	reverse_B = reverse(B);
	result_A = stoi(reverse_A);
	result_B = stoi(reverse_B);
	printf("%d\n", result_A > result_B ? result_A : result_B);
	return 0;
}