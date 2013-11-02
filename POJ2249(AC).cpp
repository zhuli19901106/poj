#include <stdio.h>

int c(int n, int k)
{
	int i;
	double result;

	if(k == 0 || k == n)
	{
		return 1;
	}
	else if(n < k)
	{
		return 0;
	}
	else if(k > n / 2)
	{
		return c(n, n - k);
	}
	else
	{
		result = 1.0;
		for(i = k - 1; i >= 0; i--)
		{
			result = result * (1.0 * n - i) / (1.0 * k - i);
		}

		return result;
	}
}

int main()
{
	int n;
	int k;

	while(1)
	{
		scanf("%d%d", &n, &k);
		if(n == 0 && k == 0)
		{
			break;
		}

		printf("%d\n", c(n, k));
	}

	return 0;
}

