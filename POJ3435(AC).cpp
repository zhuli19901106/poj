#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNDEFINED 0
#define CORRECT 1
#define INCORRECT 2

int main()
{
	int n;
	int n2;
	int n4;
	int i;
	int j;
	int p;
	int q;
	int a[101][101];
	int row[101];
	int col[101];
	int square[101];
	int isChecked;

	scanf("%d", &n);
	n2 = n * n;
	n4 = n2 * n2;

	for(i = 1; i <= n2; i++)
	{
		for(j = 1; j <= n2; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	isChecked = UNDEFINED;
	for(i = 1; isChecked == UNDEFINED && i <= n2; i++)
	{
		memset(row, 0, (n2 + 1) * sizeof(int));
		memset(col, 0, (n2 + 1) * sizeof(int));
		for(j = 1; isChecked == UNDEFINED && j <= n2; j++)
		{
			if(a[i][j] > 0)
			{
				if(row[a[i][j]] == 0)
				{
					row[a[i][j]] = 1;
				}
				else
				{
					isChecked = INCORRECT;
					break;
				}
			}

			if(a[j][i] > 0)
			{
				if(col[a[j][i]] == 0)
				{
					col[a[j][i]] = 1;
				}
				else
				{
					isChecked = INCORRECT;
					break;
				}
			}
		}
	}

	for(i = 0; isChecked == UNDEFINED && i < n; i++)
	{
		for(j = 0; isChecked == UNDEFINED && j < n; j++)
		{
			memset(square, 0, (n2 + 1) * sizeof(int));
			for(p = 1; isChecked == UNDEFINED && p <= n; p++)
			{
				for(q = 1; isChecked == UNDEFINED && q <= n; q++)
				{
					if(a[i * n + p][j * n + q] > 0)
					{
						if(square[a[i * n + p][j * n + q]] == 0)
						{
							square[a[i * n + p][j * n + q]] = 1;
						}
						else
						{
							isChecked = INCORRECT;
							break;
						}
					}
				}
			}
		}
	}

	if(isChecked == UNDEFINED)
	{
		isChecked = CORRECT;
	}

	switch(isChecked)
	{
	case CORRECT:
		printf("CORRECT\n");
		break;
	case INCORRECT:
		printf("INCORRECT\n");
		break;
	}

	return 0;
}

