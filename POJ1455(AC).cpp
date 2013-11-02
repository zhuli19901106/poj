#include <stdio.h>

long f(int n)
{
	return (n - 1) * n / 2;
}

int main()
{
	int i;
	int t;
	long n;

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%ld", &n);
		if(n % 2 == 0)
		{
			printf("%ld\n", 2 * f(n / 2));
		}
		else
		{
			printf("%ld\n", f((n + 1) / 2) + f((n - 1) / 2));
		}
	}

	return 0;
}

