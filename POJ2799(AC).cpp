#include <stdio.h>
#include <string.h>

typedef unsigned long dword;

dword getdword(dword bytes[])
{
	dword result;

	result = 0;
	result += bytes[3];
	result *= 256;
	result += bytes[2];
	result *= 256;
	result += bytes[1];
	result *= 256;
	result += bytes[0];

	return result;
}

void getbytes(dword ip, dword bytes[])
{
	int i;

	for(i = 0; i < 4; i++)
	{
		bytes[i] = ip % 256;
		ip = ip / 256;
	}
}

int main()
{
	char buffer[1000];
	dword bytes[4];
	dword ip;
	dword lowerbound;
	dword upperbound;
	dword tmp;
	dword base;
	dword mask;
	dword network;
	int count;
	int n;
	int i;

	while(1)
	{
		if(gets(buffer) == NULL)
		{
			break;
		}
		sscanf(buffer, "%d", &n);

		lowerbound = 0xffffffff;
		upperbound = 0x00000000;
		for(i = 0; i < n; i++)
		{
			gets(buffer);
			sscanf(buffer, "%lu.%lu.%lu.%lu", &bytes[3], &bytes[2], &bytes[1], &bytes[0]);
			ip = getdword(bytes);
			if(ip < lowerbound)
			{
				lowerbound = ip;
			}
			if(ip > upperbound)
			{
				upperbound = ip;
			}
		}

		tmp = lowerbound ^ upperbound;
		base = 0x80000000;
		mask = 0x00000000;
		count = 0;
		while(base > 0 && (tmp & base) == 0)
		{
			mask = mask + base;
			base = base / 2;
			count++;
		}

		network = lowerbound & mask;
		getbytes(network, bytes);
		printf("%lu.%lu.%lu.%lu\n", bytes[3], bytes[2], bytes[1], bytes[0]);
		getbytes(mask, bytes);
		printf("%lu.%lu.%lu.%lu\n", bytes[3], bytes[2], bytes[1], bytes[0]);
	}

	return 0;
}

