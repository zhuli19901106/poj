#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[1000];
	int len;
	int i;
	int minus;
	long value;
	long base;

	while(1)
	{
		gets(buffer);
		if(strcmp(buffer, "0") == 0)
		{
			break;
		}

		len = strlen(buffer);
		minus = 0;
		value = 0;
		base = 1;
		for(i = len - 1; i >= 0; i--)
		{
			base = base * 2;
			minus = minus + buffer[i] - '0';
			if(buffer[i] - '0' > 0)
			{
				value = value + (buffer[i] - '0') * base;
			}
		}

		value = value - minus;
		printf("%ld\n", value);
	}

	return 0;
}

