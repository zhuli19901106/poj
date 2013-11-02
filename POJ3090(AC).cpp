#include <stdio.h>
#include <math.h>

/*
int gcd(int a, int b)
{
	if(a == b)
	{
		return a;
	}

	while(1)
	{
		if(a > b)
		{
			if(a % b == 0)
			{
				return b;
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
				return a;
			}
			else
			{
				b = b % a;
			}
		}
	}
}
*/

int isprime(int n)
{
	int i;
	double rt;

	if(n <= 1)
	{
		return 0;
	}
	else if(n == 2)
	{
		return 1;
	}
	else
	{
		rt = sqrt(1.0 * n);
		for(i = 2; i <= rt; i++)
		{
			if(n % i == 0)
			{
				return 0;
			}
		}

		return 1;
	}
}

int main()
{
	int n0;
	int n;
	int i;
	int t;
	int casecount;
	int factorcount;
	int factors[100];
	double eu[1050];
	double sums[1050];

	eu[0] = eu[1] = 0;
	eu[2] = 1;
	for(n0 = 3; n0 < 1050; n0++)
	{
		n = n0;
		eu[n0] = n0;
		i = 2;
		factorcount = 0;
		while(1)
		{
			if(n % i == 0)
			{
				factors[factorcount] = i;
				factorcount++;
				while(n % i == 0)
				{
					n = n / i;
				}

				if(n == 1)
				{
					break;
				}
				else if(isprime(n))
				{
					factors[factorcount] = n;
					factorcount++;
					break;
				}
			}
			else
			{
				i++;
			}
		}

		for(i = 0; i < factorcount; i++)
		{
			eu[n0] = eu[n0] * (factors[i] - 1) / factors[i];
		}
	}

	sums[0] = eu[0];
	for(i = 0; i < 1049; i++)
	{
		sums[i + 1] = sums[i] + eu[i];
	}

	scanf("%d", &t);
	for(casecount = 1; casecount <= t; casecount++)
	{
		scanf("%d", &n);

		printf("%d %d %d\n", casecount, n, (int)(sums[n + 1] * 2 + 3));
	}

	return 0;
}

