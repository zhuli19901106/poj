#include <stdio.h>

int main()
{
	int n;
	int m;
	int i;
	int j;
	long a[18][18];
	long product;
	long sum;

	scanf("%d%d", &n, &m);
	
	for(i = 0; i < 18; i++)
	{
		for(j = 0; j < 18; j++)
		{
			a[i][j] = 0;
		}
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			scanf("%ld", &a[i][j]);
		}
	}

	sum = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			product = a[i][j] * a[i - 1][j];
			if(product > 0)
			{
				sum = sum + product;
			}
			product = a[i][j] * a[i + 1][j];
			if(product > 0)
			{
				sum = sum + product;
			}
			product = a[i][j] * a[i][j - 1];
			if(product > 0)
			{
				sum = sum + product;
			}
			product = a[i][j] * a[i][j + 1];
			if(product > 0)
			{
				sum = sum + product;
			}
		}
	}
	sum = sum / 2;
	printf("%ld\n", sum);

	return 0;
}

