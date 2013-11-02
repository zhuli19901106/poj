#include <stdio.h>
#include <string.h>
#define MAX_ITEM_LENGTH 100

int cutstring(const char instr[], char out[][MAX_ITEM_LENGTH], const int maxarg)
{
	int i, j;
	int n;
	int copy;

	i = 0;
	j = 0;
	n = 0;
	copy = 0;
	while(1)
	{
		if(instr[i] == 0)
		{
			out[n][j] = 0;
			n++;
			break;
		}
		else if(instr[i] == ' ')
		{
			if(copy == 0)
			{
				i++;
			}
			else
			{
				copy = 0;
				out[n][j] = 0;
				i++;
				j = 0;
				n++;
			}
		}
		else
		{
			if(copy == 0)
			{
				copy = 1;
				out[n][j] = instr[i];
				i++;
				j++;
			}
			else
			{
				out[n][j] = instr[i];
				i++;
				j++;
			}
		}
	}

	return n;
}

int findword(const char str[], const char dict[][17], int m)
{
	int i;

	for(i = 0; i < m; i++)
	{
		if(strcmp(str, dict[i]) == 0)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int i;
	int j;
	int m;
	int n;
	int wordcount;
	int findindex;
	char dict[1000][17];
	char words[100][100];
	long weight[1000];
	char buffer[1000];
	long salary;

	gets(buffer);
	sscanf(buffer, "%d %d", &m, &n);
	for(i = 0; i < m; i++)
	{
		gets(buffer);
		sscanf(buffer, "%s %ld", dict[i], &weight[i]);
	}

	for(i = 0; i < n; i++)
	{
		salary = 0;
		while(1)
		{
			gets(buffer);
			if(strcmp(buffer, ".") == 0)
			{
				break;
			}

			wordcount = cutstring(buffer, words, 100);
			for(j = 0; j < wordcount; j++)
			{
				findindex = findword(words[j], dict, m);
				if(findindex != -1)
				{
					salary += weight[findindex];
				}
			}
		}
		printf("%ld\n", salary);
	}

	return 0;
}

