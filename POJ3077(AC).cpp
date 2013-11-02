#include <stdio.h>

int main()
{
	int base;
	int i;
	int n;
	int t;
	int rem;

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		base = 10;
		while(n > base)
		{
			rem = n % base;
			if(rem / (base / 10) >= 5)
			{
				n = n / base * base + base;
			}
			else
			{
				n = n / base * base;
			}
			base = base * 10;
		}
		printf("%d\n", n);
	}

	return 0;
}

