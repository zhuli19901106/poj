#include <stdio.h>
#include <string.h>

int getcode(const char ch)
{
	switch(ch)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		return 1;
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		return 2;
	case 'D':
	case 'T':
		return 3;
	case 'L':
		return 4;
	case 'M':
	case 'N':
		return 5;
	case 'R':
		return 6;
	default:
		return 0;
	}
}

int main()
{
	int i;
	int len;
	char buffer[100];
	int oldcode;
	int code;
	char ch;

	while(1)
	{
		if(scanf("%s", buffer) != 1)
		{
			break;
		}

		len = strlen(buffer);
		ch = buffer[0];
		code = getcode(ch);
		if(code != 0)
		{
			printf("%d", code);
		}
		for(i = 1; i < len; i++)
		{
			oldcode = code;
			if(buffer[i] != ch)
			{
				ch = buffer[i];
				code = getcode(ch);
				if(code != 0 && oldcode != code)
				{
					printf("%d", code);
				}
			}
		}
		printf("\n");
	}

	return 0;
}

