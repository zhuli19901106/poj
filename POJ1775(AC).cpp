#include <stdio.h>

int main()
{
	int i;
	long n;
	long fac[] = {
		1,
		1,
		2,
		6,
		24,
		120,
		720,
		5040,
		40320,
		362880,
		3628800
	};

	while(1)
	{
		scanf("%ld", &n);
		if(n < 0)
		{
			break;
		}
		else
		{
			i = 9;
			while(i >= 0)
			{
				while(fac[i] > n)
				{
					i--;
				}
				n = n - fac[i];
				if(n == 0)
				{
					break;
				}
				else
				{
					i--;
				}
			}
			if(i >= 0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}

	return 0;
}

