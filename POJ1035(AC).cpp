#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
	return (a > b ? b : a);
}

int main()
{
	int i;
	int j;
	int count;
	int correct;
	int difcount;
	char *dict[10001];
	char word[100];
	char line[1000];

	for(i = 0; i < 10001; i++)
	{
		dict[i] = (char *)malloc(17 * sizeof(char));
	}

	count = 0;
	while(1)
	{
		gets(line);
		if(strcmp(line, "#") == 0)
		{
			break;
		}

		strcpy(dict[count], line);
		count++;
	}

	while(1)
	{
		gets(word);
		if(strcmp(word, "#") == 0)
		{
			break;
		}
		else
		{
			correct = 0;
			for(i = 0; i < count; i++)
			{
				if(strcmp(word, dict[i]) == 0)
				{
					correct = 1;
					break;
				}
			}

			if(correct == 1)
			{
				printf("%s is correct\n", word);
			}
			else
			{
				printf("%s:", word);

				for(i = 0; i < count; i++)
				{

					if(strlen(word) - strlen(dict[i]) == 0)
					{
						difcount = 0;
						for(j = 0; j < strlen(word); j++)
						{
							if(word[j] != dict[i][j])
							{
								difcount++;
							}
						}
						if(difcount == 1)
						{
							printf(" %s", dict[i]);
						}
					}
					else if(strlen(word) - strlen(dict[i]) == 1)
					{
						for(j = 0; j < strlen(dict[i]); j++)
						{
							if(word[j] != dict[i][j])
							{
								break;
							}
						}

						for(; j < strlen(dict[i]); j++)
						{
							if(word[j + 1] != dict[i][j])
							{
								break;
							}
						}

						if(j == strlen(dict[i]))
						{
							printf(" %s", dict[i]);
						}
					}
					else if(strlen(word) - strlen(dict[i]) == -1)
					{
						for(j = 0; j < strlen(word); j++)
						{
							if(word[j] != dict[i][j])
							{
								break;
							}
						}

						for(; j < strlen(word); j++)
						{
							if(word[j] != dict[i][j + 1])
							{
								break;
							}
						}

						if(j == strlen(word))
						{
							printf(" %s", dict[i]);
						}
					}
				}

				printf("\n");
			}
		}
	}

	for(i = 0; i < 10001; i++)
	{
		free(dict[i]);
	}

	return 0;
}

