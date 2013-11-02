#include <stdio.h>
#include <string.h>

int main()
{
	char line[5000];
	char nextline[5000];
	char buffer[500];
	int i;
	int j;
	int t;
	int count;
	int digit;
	int olddigit;

	gets(line);
	sscanf(line, "%d", &t);
	for(i = 0; i < t; i++)
	{
		gets(line);
		strcpy(nextline, "");
		olddigit = -1;
		for(j = 0; j <= strlen(line); j++)
		{
			if(j < strlen(line))
			{
				digit = line[j] - '0';
				if(digit != olddigit)
				{
					if(olddigit != -1)
					{
						sprintf(buffer, "%d%d", count, olddigit);
						strcat(nextline, buffer);
					}
					olddigit = digit;
					count = 1;
				}
				else
				{
					count++;
				}
			}
			else
			{
				sprintf(buffer, "%d%d", count, olddigit);
				strcat(nextline, buffer);
			}
		}

		puts(nextline);
	}

	return 0;
}

