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
	int n;
	int i;
	int factorcount;
	int factors[100];
	double eu;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}
		else if(n == 1)
		{
			printf("0\n");
		}
		else if(isprime(n))
		{
			printf("%d\n", n - 1);
		}
		else
		{
			eu = n;
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
				eu = eu * (factors[i] - 1) / factors[i];
			}

			printf("%d\n", (int)eu);
		}
	}

	return 0;
}

