#include <stdio.h>

void getbits(int integer, int bits[])
{
	int i;
	int bit;


	i = 0;
	while(integer > 0)
	{
		bits[i] = integer % 2;
		integer = integer / 2;
		i++;
	}
}

int main()
{
	int n;
	int i;
	int j;
	int k;
	int bits[3][6];
	int hour;
	int minute;
	int second;
	char vertical[100];
	char horizontal[100];
	int counter;

	counter = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 6; k++)
			{
				bits[j][k] = 0;
			}
		}

		scanf("%2d:%2d:%2d", &hour, &minute, &second);
		getbits(hour, bits[0]);
		getbits(minute, bits[1]);
		getbits(second, bits[2]);

		for(j = 0; j < 18; j++)
		{
			vertical[j] = bits[j % 3][5 - j / 3] + '0';
			horizontal[j] = bits[j / 6][5 - j % 6] + '0';
		}

		vertical[j] = 0;
		horizontal[j] = 0;

		counter++;
		printf("%d %s %s\n", counter, vertical, horizontal);
	}

	return 0;
}

