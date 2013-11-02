#include <stdio.h>

int main()
{
	long i;
	double len;
	double sum;

	while(1)
	{
		scanf("%lf", &len);
		if(len <= 0)
		{
			break;
		}

		i = 2;
		sum = 0;
		while(1)
		{
			sum = sum + 1.0 / i;
			if(sum > len)
			{
				break;
			}
			else
			{
				i++;
			}
		}

		printf("%ld card(s)\n", i - 1);
	}

	return 0;
}

