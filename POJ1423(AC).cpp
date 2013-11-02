#include <math.h>
#include <stdio.h>

int main()
{
	const double pi = 3.1415926535;
	const double e = 2.718281828;
	double sum;
	long n;
	long i;
	long num;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(num == 1)
		{
			printf("1\n");
		}
		else
		{
			sum = log(2 * pi * num) / log(10.0) / 2.0 + num * log(num / e) / log(10.0);
			printf("%d\n", (int)sum + 1);
		}
	}
	
	return 0;
}

