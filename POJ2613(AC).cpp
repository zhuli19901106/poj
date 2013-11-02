#include <stdio.h>

int main()
{
	int p, q, r, s;
	int i;
	int j;
	double result;
	double termpq;
	double termrs;

	while(1)
	{
		if(scanf("%d%d%d%d", &p, &q, &r, &s) != 4)
		{
			break;
		}

		if(q > p / 2)
		{
			q = p - q;
		}

		if(s > r / 2)
		{
			s = r - s;
		}

		result = 1.0;
		i = 0;
		j = s - 1;
		while(i < q || j > -1)
		{
			if(result <= 100000000)
			{
				if(i < q && j > -1)
				{
					termpq = (1.0 * p - i) / (1.0 * q - i);
					result = result * termpq;
					i++;
				}
				else if(i == q && j > -1)
				{
					termrs = (1.0 * s - j) / (1.0 * r - j);
					result = result * termrs;
					j--;
				}
				else if(i < q && j == -1)
				{
					termpq = (1.0 * p - i) / (1.0 * q - i);
					result = result * termpq;
					i++;
				}
			}
			else
			{
				if(i < q && j > -1)
				{
					termrs = (1.0 * s - j) / (1.0 * r - j);
					result = result * termrs;
					j--;
				}
				else if(i == q && j > -1)
				{
					termrs = (1.0 * s - j) / (1.0 * r - j);
					result = result * termrs;
					j--;
				}
				else if(i < q && j == -1)
				{
					termpq = (1.0 * p - i) / (1.0 * q - i);
					result = result * termpq;
					i++;
				}
			}
		}

		printf("%0.5f\n", result);
	}

	return 0;
}

