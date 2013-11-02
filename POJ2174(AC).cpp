#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int todec(char ch)
{
	if(ch >= 'A' && ch <= 'F')
	{
		return ch - 'A' + 10;
	}
	else if(ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else
	{
		return -1;
	}
}

char tohex(int i)
{
	if(i >= 10 && i <= 15)
	{
		return i - 10 + 'A';
	}
	else if(i >= 0 && i <= 9)
	{
		return i + '0';
	}
	else
	{
		return 0;
	}
}

int main()
{
	char msg1[20001];
	char msg2[20003];
	int n;
	int i;
	int bytes1[10000];
	int bytes2[10001];
	int ctext[10000];
	int key[10001];

	gets(msg1);
	gets(msg2);
	n = strlen(msg1) / 2;
	for(i = 0; i < n; i++)
	{
		bytes1[i] = todec(msg1[2 * i]) * 16 + todec(msg1[2 * i + 1]);
	}

	for(i = 0; i < n + 1; i++)
	{
		bytes2[i] = todec(msg2[2 * i]) * 16 + todec(msg2[2 * i + 1]);
	}

	key[0] = bytes2[0] ^ 32;
	for(i = 1; i < n + 1; i++)
	{
		ctext[i - 1] = bytes1[i - 1] ^ key[i - 1];
		key[i] = bytes2[i] ^ ctext[i - 1];
	}

	for(i = 0; i < n + 1; i++)
	{
		printf("%c%c", tohex(key[i] / 16), tohex(key[i] % 16));
	}
	printf("\n");

	return 0;
}

