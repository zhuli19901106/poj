#include <math.h>
#include <stdio.h>

int main()
{
	double p;
	double k;
	int n;

	while(1)
	{
		if(scanf("%d%lf", &n, &p) != 2)
		{
			break;
		}

		k = pow(p, 1.0 / n);
		printf("%g\n", k);
	}

	return 0;
}

