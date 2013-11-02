#include <stdio.h>
#include <string.h>
#define MAXLEN 1005

int main()
{
	char a[1050];
	char b[1050];
	int digita[MAXLEN];
	int digitb[MAXLEN];
	int digitc[MAXLEN];
	int counta;
	int countb;
	int i;
	int carry;
	int len;

	while(1)
	{
		if(scanf("%s%s", a, b) != 2)
		{
			break;
		}

		if(strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
		{
			break;
		}

		for(i = 0; i < MAXLEN; i++)
		{
			digita[i] = digitb[i] = digitc[i] = 0;
		}

		len = strlen(a);
		counta = len;
		for(i = len - 1; i >= 0; i--)
		{
			digita[i] = a[len - 1 - i] - '0';
		}

		len = strlen(b);
		countb = len;
		for(i = len - 1; i >= 0; i--)
		{
			digitb[i] = b[len - 1 - i] - '0';
		}

		for(i = 0; i < MAXLEN; i++)
		{
			digitc[i] = digita[i] + digitb[i];
		}

		carry = 0;
		for(i = 0; i < MAXLEN; i++)
		{
			if(digitc[i] > 9)
			{
				digitc[i] = digitc[i] - 10;
				digitc[i + 1]++;
				carry++;
			}
		}

		if(carry == 0)
		{
			printf("No carry operation.\n");
		}
		else if(carry == 1)
		{
			printf("1 carry operation.\n");
		}
		else
		{
			printf("%d carry operations.\n", carry);
		}
	}

	return 0;
}

