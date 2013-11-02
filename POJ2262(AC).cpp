#include <math.h>
#include <stdio.h>

int isprime(int n)
{
	int i;
	double rt;

	if(n < 2)
	{
		return 0;
	}
	else if(n == 2)
	{
		return 1;
	}

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

int main()
{
	int a;
	int n;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}
		else
		{
			a = 2;
			while(1)
			{
				if(!isprime(a) || !isprime(n - a))
				{
					a++;
				}
				else
				{
					printf("%d = %d + %d\n", n, a, n - a);
					break;
				}
			}
		}
	}

	return 0;
}

