#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH (100 + 1)

typedef struct
{
	int len;
	int res;
} sumres;

sumres sum(char* arr, int cur_idx)
{
	int idx = cur_idx + 1;
	int len = 0;
	char tmp[MAX_LENGTH];
	char* tok;
	int result;
	sumres ret;
	while (1)
	{
		if (arr[idx] == ')')
		{
			break;
		}
		else
		{
			tmp[len++] = arr[idx];
		}
		idx += 1;
	}
	tok = strtok(tmp, "+");
	result = 0;
	while (tok != NULL)
	{
		result += atoi(tok);
		//printf("%d\n", result);
		tok = strtok(NULL, "+");
	}
	ret.len = len;
	ret.res = result;
	return ret;
}

int assert_test(char* arr)
{
	for (int i = 0; i < strlen(arr); i++)
	{
		assert(arr[i] == '-');
	}
	return 0;
}

int main(void)
{
	char str[MAX_LENGTH];
	char* new_str;
	int len;
	sumres ret;
	int result;
	int idx;

	scanf("%s", str);
	assert_test(str);

	new_str = (char*)malloc(sizeof(char) * MAX_LENGTH * 10);
	new_str[0] = '(';
	len = 1;
	for (int idx = 0; idx < strlen(str); idx++)
	{
		if (str[idx] == '-')
		{
			new_str[len++] = ')';
			new_str[len++] = '-';
			new_str[len++] = '(';
		}
		else
		{
			new_str[len++] = str[idx];
		}
	}
	new_str[len++] = ')';
	new_str[len++] = 0;
	//printf("%s\n", new_str);
	idx = 0;
	for (int i = 0; i < len; i++)
	{
		if (new_str[i] == '(')
		{
			ret = sum(new_str, i);
			//printf("%d\n", ret.res);
			if (idx == 0)
			{
				result = ret.res;
			}
			else
			{
				if (new_str[i - 1] == '+')
				{
					result += ret.res;
				}
				else if (new_str[i - 1] == '-')
				{
					result -= ret.res;
				}
			}
			i += ret.len;
			idx += 1;
		}
	}
	printf("%d\n", result);
}