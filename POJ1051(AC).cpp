#include <stdio.h>
#include <string.h>

char dict[30][5] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
	"..--",
	"---.",
	".-.-",
	"----"
};


char GetChar(const char str[])
{
	int i;

	for(i = 0; i < 26; i++)
	{
		if(strcmp(str, dict[i]) == 0)
		{
			return i + 'A';
		}
	}

	if(strcmp(str, dict[26]) == 0)
	{
		return '_';
	}
	else if(strcmp(str, dict[27]) == 0)
	{
		return '.';
	}
	else if(strcmp(str, dict[28]) == 0)
	{
		return ',';
	}
	else if(strcmp(str, dict[29]) == 0)
	{
		return '?';
	}
	else
	{
		return 0;
	}
}

char *GetMorseCode(const char ch)
{
	if(ch >= 'A' && ch <= 'Z')
	{
		return dict[ch - 'A'];
	}
	else if(ch == '_')
	{
		return dict[26];
	}
	else if(ch == '.')
	{
		return dict[27];
	}
	else if(ch == ',')
	{
		return dict[28];
	}
	else if(ch == '?')
	{
		return dict[29];
	}
	else
	{
		return NULL;
	}
}

int main()
{
	int n;
	int i;
	int j;
	int k;
	int t;
	int len;
	int pos;
	char cht;
	char line[500];
	char output[500];
	char code[2000];
	char *tmp;
	int lens[200];

	while(scanf("%d", &n) != EOF)
	{
		getchar();

		for(i = 0; i < n; i++)
		{
			gets(line);
			len = strlen(line);

			code[0] = 0;
			for(j = 0; j < len; j++)
			{
				tmp = GetMorseCode(line[j]);
				lens[j] = strlen(tmp);
				strcat(code, tmp);
			}

			j = 0;
			k = len - 1;
			while(j < k)
			{
				t = lens[j];
				lens[j] = lens[k];
				lens[k] = t;
				j++;
				k--;
			}

			pos = 0;
			for(j = 0; j < len; j++)
			{
				cht = code[pos + lens[j]];
				code[pos + lens[j]] = 0;
				output[j] = GetChar(code + pos);
				code[pos + lens[j]] = cht;
				pos = pos + lens[j];
			}
			output[j] = 0;
			printf("%d: %s\n", i + 1, output);
		}
	}

	return 0;
}

