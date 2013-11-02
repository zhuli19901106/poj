#include <stdio.h>
#include <string.h>

long GetDigit(long n, long digit)
{
	char buffer[100];

	sprintf(buffer, "%ld", n);

	if(digit > strlen(buffer))
	{
		return -1;
	}
	else
	{
		return (buffer[digit - 1] - '0');
	}
}

int main()
{
	int isContinue;
	int isContinue2;
	long i;
	long j;
	long t;
	long n;
	long n0;
	long seqNum;
	long seqLeft;
	long seqLen;
	long finalNum;

	scanf("%ld", &t);

	for(i = 0; i < t; i++)
	{
		scanf("%ld", &n);
		n0 = n;
		seqLen = 0;

		isContinue = 1;
		for(j = 1; j <= 9 && isContinue == 1; j++)
		{
			seqLen += 1;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 10; j <= 99 && isContinue == 1; j++)
		{
			seqLen += 2;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 100; j <= 999 && isContinue == 1; j++)
		{
			seqLen += 3;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 1000; j <= 9999 && isContinue == 1; j++)
		{
			seqLen += 4;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 10000; j <= 99999 && isContinue == 1; j++)
		{
			seqLen += 5;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 100000; j <= 999999 && isContinue == 1; j++)
		{
			seqLen += 6;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 1000000; j <= 9999999 && isContinue == 1; j++)
		{
			seqLen += 7;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 10000000; j <= 99999999 && isContinue == 1; j++)
		{
			seqLen += 8;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 100000000; j <= 999999999 && isContinue == 1; j++)
		{
			seqLen += 9;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		for(j = 1000000000; j <= 2147483647 && isContinue == 1; j++)
		{
			seqLen += 10;
			if(n0 <= seqLen)
			{
				isContinue = 0;
				seqNum = j;
				seqLeft = n0;
			}
			else
			{
				n0 -= seqLen;
			}
		}

		isContinue2 = 1;

		for(j = 1; j <= 9 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 1)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 1;
			}
		}

		for(j = 10; j <= 99 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 2)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 2;
			}
		}

		for(j = 100; j <= 999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 3)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 3;
			}
		}

		for(j = 1000; j <= 9999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 4)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 4;
			}
		}

		for(j = 10000; j <= 99999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 5)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 5;
			}
		}

		for(j = 100000; j <= 999999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 6)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 6;
			}
		}

		for(j = 1000000; j <= 9999999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 7)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 7;
			}
		}

		for(j = 10000000; j <= 99999999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 8)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 8;
			}
		}

		for(j = 100000000; j <= 999999999 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 9)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 9;
			}
		}

		for(j = 1000000000; j <= 2147483647 && isContinue2 == 1; j++)
		{
			if(seqLeft <= 10)
			{
				finalNum = j;
				isContinue2 = 0;
			}
			else
			{
				seqLeft -= 10;
			}
		}

		printf("%ld\n", GetDigit(finalNum, seqLeft));
	}

	return 0;
}

