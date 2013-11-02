#include <stdio.h>
#include <string.h>

long get9(int n)
{
	long result;
	int i;

	result = 0;
	for(i = 0; i < n; i++)
	{
		result = result * 10;
		result = result + 9;
	}

	return result;
}

void reverse(char a[], int left, int right)
{
	int i;
	int j;
	char ch;

	if(left >= right)
	{
		return;
	}

	i = left;
	j = right;
	while(i < j)
	{
		ch = a[i];
		a[i] = a[j];
		a[j] = ch;
		i++;
		j--;
	}
}

int main()
{
	long count[] = {
		0,
		9,
		9,
		90,
		90,
		900,
		900,
		9000,
		9000,
		90000,
		90000,
		900000,
		900000,
		9000000,
		9000000,
		90000000,
		90000000,
		900000000,
		900000000
	};
	long i;
	long n;
	long n0;
	char str[30];
	char inv[30];

	while(1)
	{
		scanf("%ld", &n);
		if(n == 0)
		{
			break;
		}

		n0 = n;
		i = 1;
		while(n0 > 0)
		{
			n0 = n0 - count[i];
			i++;
		}
		i--;
		n0 = n0 + count[i];
		if(i % 2 == 1)
		{
			n0 = n0 + get9((i - 1) / 2);
			sprintf(str, "%ld", n0);
			strcpy(inv, str);
			reverse(inv, 0, strlen(inv) - 1);
			str[strlen(str) - 1] = 0;
			strcat(str, inv);
		}
		else
		{
			n0 = n0 + get9(i / 2 - 1);
			sprintf(str, "%ld", n0);
			strcpy(inv, str);
			reverse(inv, 0, strlen(inv) - 1);
			strcat(str, inv);
		}
		puts(str);
	}

	return 0;
}

