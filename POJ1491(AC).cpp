#include <math.h>
#include <stdio.h>

int check(int a, int b)
{
	if(a == b)
	{
		if(a > 1)
		{
			return 1;
		}
		else if(a == 0)
		{
			return 0;
		}
	}

	while(1)
	{
		if(a > b)
		{
			if(a % b == 0)
			{
				if(b == 1)
				{
					return 0;
				}
				else if(b > 1)
				{
					return 1;
				}
			}
			else
			{
				a = a % b;
			}
		}
		else
		{
			if(b % a == 0)
			{
				if(a == 1)
				{
					return 0;
				}
				else if(a > 1)
				{
					return 1;
				}
			}
			else
			{
				b = b % a;
			}
		}
	}
}

int main()
{
	int i;
	int j;
	int n;
	int a[100];
	int count;
	int total;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		total = n * (n - 1) / 2;
		count = 0;
		for(i = 0; i < n - 1; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				count = count + !check(a[i], a[j]);
			}
		}

		if(count == 0)
		{
			printf("No estimate for this data set.\n");
		}
		else
		{
			printf("%0.6f\n", sqrt(6.0 * total / count));
		}
	}

	return 0;
}

