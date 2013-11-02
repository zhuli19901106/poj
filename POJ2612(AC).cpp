#include <stdio.h>

int inbound(int i, int j, int n)
{
	return ((i >= 0 && i <= n - 1) && (j >= 0 && j <= n - 1));
}

int main()
{
	int touch[10][10];
	int num[10][10];
	int n;
	int i;
	int j;
	int k;
	int adi[8] = {0, 0, 1, -1, -1, 1, -1, 1};
	int adj[8] = {1, -1, 0, 0, -1, -1, 1, 1};
	int casecount;
	int dead;
	char buffer[1000];

	casecount = 0;
	while(1)
	{
		if(gets(buffer) == NULL)
		{
			break;
		}
		else
		{
			casecount++;
		}

		sscanf(buffer, "%d", &n);
		for(i = 0; i < n; i++)
		{
			gets(buffer);
			for(j = 0; j < n; j++)
			{
				switch(buffer[j])
				{
				case '.':
					num[i][j] = 0;
					break;
				case '*':
					num[i][j] = -1;
					break;
				}
			}
		}

		for(i = 0; i < n; i++)
		{
			gets(buffer);
			for(j = 0; j < n; j++)
			{
				switch(buffer[j])
				{
				case '.':
					touch[i][j] = 0;
					break;
				case 'x':
					touch[i][j] = 1;
					break;
				}
			}
		}

		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(num[i][j] == -1)
				{
					for(k = 0; k < 8; k++)
					{
						if(inbound(i + adi[k], j + adj[k], n))
						{
							if(num[i + adi[k]][j + adj[k]] != -1)
							{
								num[i + adi[k]][j + adj[k]]++;
							}
						}
					}
				}
			}
		}

		dead = 0;
		for(i = 0; dead == 0 && i < n; i++)
		{
			for(j = 0; dead == 0 && j < n; j++)
			{
				if(touch[i][j] == 1 && num[i][j] == -1)
				{
					dead = 1;
				}
			}
		}

		if(casecount > 1)
		{
			printf("\n");
		}

		if(dead == 0)
		{
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(touch[i][j] == 1)
					{
						printf("%d", num[i][j]);
					}
					else
					{
						printf(".");
					}
				}
				printf("\n");
			}
		}
		else
		{
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(num[i][j] == -1)
					{
						printf("*");
					}
					else if(touch[i][j] == 1)
					{
						printf("%d", num[i][j]);
					}
					else
					{
						printf(".");
					}
				}
				printf("\n");
			}
		}
	}

	return 0;
}

