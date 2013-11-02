#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
	char text[1000];
	int len = strlen(str);
	int i;
	int k;

	while(gets(text) != NULL)
	{
		for(k = 0; k< strlen(text); k++)
		{
			if(text[k] == ' ')
			{
				printf("%c", text[k]);
			}

			for(i = 0; i < len; i++)
			{
				if(text[k] == str[i])
				{
					printf("%c", str[i-1]);
				}
			}
		}
		printf("\n");
	}

	return 0;
}

