#include <stdio.h>

int main()
{
	int i;
	int j;
	int k;
	int n;
	char buffer[100];
	int ip[4];
	int bits[8] = {
		1,
		2,
		4,
		8,
		16,
		32,
		64,
		128
	};

	gets(buffer);
	sscanf(buffer, "%d", &n);
	for(i = 0; i < n; i++)
	{
		gets(buffer);
		for(j = 0; j < 4; j++)
		{
			ip[j] = 0;
			for(k = 0; k < 8; k++)
			{
				if(buffer[j * 8 + k] == '1')
				{
					ip[j] += bits[7 - k];
				}
			}
		}
		printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
	}

	return 0;
}

