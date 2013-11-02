#include <stdio.h>
#define MAX 105

int main()
{
	int a[MAX][MAX];
	int n;
	int i;
	int j;
	int rowsum[MAX];
	int badrow;
	int badrowcount;
	int colsum[MAX];
	int badcol;
	int badcolcount;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		badrowcount = 0;
		badcolcount = 0;
		badrow = -1;
		badcol = -1;
		for(i = 0; i < n; i++)
		{
			rowsum[i] = 0;
			colsum[i] = 0;
			for(j = 0; j < n; j++)
			{
				rowsum[i] = rowsum[i] + a[i][j];
				colsum[i] = colsum[i] + a[j][i];
			}
			if(rowsum[i] % 2 == 1)
			{
				badrowcount++;
				if(badrow == -1)
				{
					badrow = i;
				}
			}
			if(colsum[i] % 2 == 1)
			{
				badcolcount++;
				if(badcol == -1)
				{
					badcol = i;
				}
			}
		}

		if(badrowcount == 0 && badcolcount == 0)
		{
			printf("OK\n");
		}
		else if(badrowcount == 1 && badcolcount == 1)
		{
			printf("Change bit (%d,%d)\n", badrow + 1, badcol + 1);
		}
		else
		{
			printf("Corrupt\n");
		}
	}

	return 0;
}

