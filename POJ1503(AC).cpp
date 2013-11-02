#include <stdio.h>
#include <string.h>

void AddDigits(int sum[], int a[], int maxdigit)
{
	int i;

	for(i = 0; i < maxdigit; i++)
	{
		sum[i] = sum[i] + a[i];
	}

	for(i = 0; i < maxdigit; i++)
	{
		if(sum[i] > 9)
		{
			sum[i] = sum[i] - 10;
			sum[i + 1]++;
		}
		else if(sum[i] < 0)
		{
			sum[i] = sum[i] + 10;
			sum[i + 1]--;
		}
	}
}


void GetDigits(int a[], char buffer[], int maxdigit)
{
	int i;
	int j;
	int len;

	len = strlen(buffer);
	i = len - 1;
	j = 0;
	while(i >= 0 && j < maxdigit)
	{
		a[j] = buffer[i] - '0';
		j++;
		i--;
	}
}

void PrintDigits(int digits[], int maxdigit)
{
	int i;

	i = maxdigit;
	while(i >= 0 && digits[i] == 0)
	{
		i--;
	}
	if(i == -1)
	{
		printf("0");
	}
	else
	{
		while(i >= 0)
		{
			printf("%c", digits[i] + '0');
			i--;
		}
	}
}

int main()
{
	int a[200];
	int sum[200];
	char buffer[1000];

	memset(a, 0, 200 * sizeof(int));
	memset(sum, 0, 200 * sizeof(int));
	while(1)
	{
		gets(buffer);
		if(strcmp(buffer, "0") == 0)
		{
			break;
		}
		else
		{
			GetDigits(a, buffer, 150);
			AddDigits(sum, a, 150);
		}
	}
	PrintDigits(sum, 150);
	puts("");

	return 0;
}

