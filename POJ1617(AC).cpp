#include <stdio.h>
#include <string.h>

int main()
{
	char keyword[21];
	int order[20];
	char cipher[2000];
	char text[110][110];
	int i;
	int j;
	int tmp;
	char ch;
	int keylen;
	int len;
	int row;
	int col;

	while(1)
	{
		gets(keyword);
		if(strcmp(keyword, "THEEND") == 0)
		{
			break;
		}

		keylen = strlen(keyword);
		for(i = 0; i < keylen; i++)
		{
			order[i] = i;
		}
		
		for(i = 0; i < keylen; i++)
		{
			ch = 'a';
			for(j = 0; j < keylen; j++)
			{
				if(keyword[j] < ch)
				{
					ch = keyword[j];  
					tmp = j;
				}
			}
			keyword[tmp] = 'Z' + 1;
			order[i] = tmp;
		}
		/*
		for(i = 0; i < keylen; i++)
		{
			printf("%3d", i + 1);
		}
		printf("\n");

		for(i = 0; i < keylen; i++)
		{
			printf("%3c", keyword[i]);
		}
		printf("\n");

		for(i = 0; i <keylen; i++)
		{
			printf("%3d", order[i] + 1);
		}
		printf("\n");
		*/
		
		gets(cipher);
		len = strlen(cipher);
		col = keylen;
		row = len / col;

		for(i = 0; i < len; i++)
		{
			text[i % row][order[i / row]] = cipher[i];
		}
		for(i = 0; i < row; i++)
		{
			text[i][col] = 0;
		}

		for(i = 0; i < row; i++)
		{
			printf("%s", text[i]);
		}
		printf("\n");
	}

	return 0;
}

