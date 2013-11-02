#include <stdio.h>

void decompress(int a[], int n)
{
	int i;
	int s[257];
	int d[257];
	int n0;

	n0 = 2;
	while(n0 <= n)
	{
		for(i = 1; i <= n0 / 2; i++)
		{
			s[i] = a[i];
		}

		for(i = 1; i <= n0 / 2; i++)
		{
			d[i] = a[n0 / 2 + i];
		}

		for(i = 1; i <= n0 / 2; i++)
		{
			a[2 * i - 1] = (s[i] + d[i]) / 2;
			a[2 * i] = (s[i] - d[i]) / 2;
		}

		n0 = n0 * 2;
	}
}

void compress(int a[], int n)
{
	int s[257];
	int d[257];
	int i;

	while(n >= 2)
	{
		for(i = 1; i <= n / 2; i++)
		{
			s[i] = a[2 * i - 1] + a[2 * i];
			d[i] = a[2 * i - 1] - a[2 * i];
		}

		for(i = 1; i <= n / 2; i++)
		{
			a[i] = s[i];
		}

		for(i = 1; i <= n / 2; i++)
		{
			a[n / 2 + i] = d[i];
		}

		n = n / 2;
	}
}

int main()
{
	int signal[257];
	int n;
	int i;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 1; i <= n; i++)
		{
			scanf("%d", &signal[i]);
		}
		decompress(signal, n);
		for(i = 1; i <= n; i++)
		{
			if(i == 1)
			{
				printf("%d", signal[i]);
			}
			else
			{
				printf(" %d", signal[i]);
			}
		}
		printf("\n");
	}

	return 0;
}

